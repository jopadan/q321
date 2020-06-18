#pragma once

namespace Demo {
	struct PackedModel {
		struct Part {
			u8			shader;
			u16			num_verts;
			u16			num_indices;
		};

		u8				num_parts;
		u16				num_verts;

		const Part*		parts;
		const u16*		verts; // separate X/Y/Z/S/T streams
		const u16*		indices;
	};

	////////////////////////////////////////////////////////////////

	namespace Model {
		enum ID {
			#define PP_ADD_MODEL_ID(name,...) name,
			DEMO_MODELS(PP_ADD_MODEL_ID)
			#undef PP_ADD_MODEL_ID

			Count,
		};

		struct Part {
			u16					num_verts;
			u16					num_indices;
			u8					shader;
			u32					ofs_verts;
			u32					ofs_idx;
		};

		struct Entry {
			u16					first_part;
			u8					num_part;
		};

		struct Vertex {
			vec3				pos;
			vec3				nor;
			vec2				uv;
		};

		namespace Storage {
			vec3*				vertices;
			vec2*				uvs;
			vec3*				normals;
			u32*				indices;
			Part*				parts;
			u16*				first_model_part;

			u32					num_verts;
			u32					num_indices;
			u32					num_parts;

			struct {
				u32				vertices;
				u32				uvs;
				u32				normals;
				u32				indices;
			}					gpu_addr;
		}

		Entry list[Model::Count];

		void LoadAll(const PackedModel* models);
		void Draw(Model::ID id);
	};
}

////////////////////////////////////////////////////////////////
// Implementation //////////////////////////////////////////////
////////////////////////////////////////////////////////////////

FORCEINLINE void Demo::Model::LoadAll(const PackedModel* models) {
	assert(!Storage::parts);

	/* count resources */
	for (u16 model_index = 0; model_index < Model::Count; ++model_index) {
		const PackedModel& packed = models[model_index];
		Storage::num_verts += packed.num_verts;
		for (u16 part_index = 0; part_index < packed.num_parts; ++part_index)
			Storage::num_indices += packed.parts[part_index].num_indices;
		Storage::num_parts += packed.num_parts;
	}

	/* alloc resources */
	Storage::vertices         = Mem::Alloc< vec3 >(Storage::num_verts);
	Storage::uvs              = Mem::Alloc< vec2 >(Storage::num_verts);
	Storage::normals          = Mem::Alloc< vec3 >(Storage::num_verts);
	Storage::indices          = Mem::Alloc< u32  >(Storage::num_indices);
	Storage::parts            = Mem::Alloc< Part >(Storage::num_parts);
	Storage::first_model_part = Mem::Alloc< u16  >(Model::Count + 1);

	MemSet(Storage::normals, 0, Storage::num_verts);

	/* initialize resources */
	u32 dst_ofs_part  = 0;
	u32 dst_ofs_verts = 0;
	u32 dst_ofs_idx   = 0;

	for (u16 model_index = 0; model_index < Model::Count; ++model_index) {
		const PackedModel& packed = models[model_index];

		const u16* src_pos = packed.verts;
		const u16* src_idx = packed.indices;

		/* model -> part association */
		Storage::first_model_part[model_index] = dst_ofs_part;

		/* part properties */
		for (u16 part_index = 0; part_index < packed.num_parts; ++part_index) {
			const PackedModel::Part& src_part = packed.parts[part_index];
			Part& dst_part = Storage::parts[dst_ofs_part++];

			dst_part.num_verts = src_part.num_verts;
			dst_part.num_indices = src_part.num_indices;
			dst_part.ofs_verts = dst_ofs_verts;
			dst_part.ofs_idx = dst_ofs_idx;

			i16 accum[5];
			MemSet(&accum);

			/* decode vertices */
			for (u32 dst_ofs_verts_end = dst_ofs_verts + src_part.num_verts; dst_ofs_verts < dst_ofs_verts_end; ++dst_ofs_verts, ++src_pos) {
				// separate XYZST streams
				float unpack[5];
				const u16* src = src_pos;
				for (u16 stream_index = 0; stream_index < 5; ++stream_index, src += packed.num_verts) {
					float div = (stream_index > 2) ? 128.f : 4.f;
					accum[stream_index] += DecodeSignMagnitude(*src);
					unpack[stream_index] = float(accum[stream_index]) / div;
				}

				MemCopy(dst_ofs_verts + Storage::vertices, unpack, 3 * sizeof(float));
				MemCopy(dst_ofs_verts + Storage::uvs, unpack + 3, 2 * sizeof(float));
			}

			/* decode indices */
			u16 watermark = 0;
			auto read_next_index = [&] {
				u16 index = watermark + 3 - *src_idx++;
				assign_max(watermark, index);
				return index;
			};

			for (u32 dst_ofs_idx_end = dst_ofs_idx + src_part.num_indices; dst_ofs_idx < dst_ofs_idx_end; /**/) {
				for (u32 i = 0; i < 3; ++i)
					Storage::indices[dst_ofs_idx++] = read_next_index();

				/* decode paired triangle */
				if (dst_ofs_idx + 2 < dst_ofs_idx_end && Storage::indices[dst_ofs_idx - 3] < Storage::indices[dst_ofs_idx - 2]) {
					Storage::indices[dst_ofs_idx + 0] = Storage::indices[dst_ofs_idx - 2];
					Storage::indices[dst_ofs_idx + 1] = Storage::indices[dst_ofs_idx - 3];
					Storage::indices[dst_ofs_idx + 2] = read_next_index();
					dst_ofs_idx += 3;
				}
			}

			assert(dst_ofs_idx == dst_part.ofs_idx + dst_part.num_indices);

			/* compute normals */
			vec3* pos = Storage::vertices + dst_part.ofs_verts;
			vec3* nor = Storage::normals + dst_part.ofs_verts;
			u32* idx = Storage::indices + dst_part.ofs_idx;
			Demo::ComputeNormals(pos, idx, dst_part.num_verts, dst_part.num_indices, nor);
		}
	}

	assert(dst_ofs_verts == Storage::num_verts);
	assert(dst_ofs_idx == Storage::num_indices);
	assert(dst_ofs_part == Storage::num_parts);

	Storage::first_model_part[Model::Count] = dst_ofs_part;

	/* upload GPU data */
	Storage::gpu_addr.vertices = Gfx::UploadGeometry(Storage::vertices, Storage::num_verts,   Gfx::Arena::Permanent);
	Storage::gpu_addr.uvs      = Gfx::UploadGeometry(Storage::uvs,      Storage::num_verts,   Gfx::Arena::Permanent);
	Storage::gpu_addr.normals  = Gfx::UploadGeometry(Storage::normals,  Storage::num_verts,   Gfx::Arena::Permanent);
	Storage::gpu_addr.indices  = Gfx::UploadGeometry(Storage::indices,  Storage::num_indices, Gfx::Arena::Permanent);
}

////////////////////////////////////////////////////////////////

NOINLINE void Demo::Model::Draw(Model::ID id) {
	Gfx::Mesh mesh;
	memset(&mesh, 0, sizeof(mesh));

	const u16
		part_begin = Model::Storage::first_model_part[id],
		part_end = Model::Storage::first_model_part[id + 1]
	;

	for (u16 part_index = part_begin; part_index < part_end; ++part_index) {
		const Model::Part& part = Storage::parts[part_index];

		u32 offset = part.ofs_verts;
		mesh.vertices[Attrib::Position	].SetData<vec3>(Storage::gpu_addr.vertices, offset);
		mesh.vertices[Attrib::TexCoord	].SetData<vec2>(Storage::gpu_addr.uvs,      offset);
		mesh.vertices[Attrib::Normal	].SetData<vec3>(Storage::gpu_addr.normals,  offset);

		mesh.index_addr			= Storage::gpu_addr.indices + part.ofs_idx * sizeof(u32);
		mesh.num_vertices		= part.num_verts;
		mesh.num_indices		= part.num_indices;

		Gfx::Draw(mesh);
	}
}
