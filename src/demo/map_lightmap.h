#pragma once

////////////////////////////////////////////////////////////////

namespace Demo {
	namespace Lightmap {
		/* Lighting parameters */
		constexpr u16
			TexelSize		= 16,
			Dilate			= true,
			JitterOccluded	= false,
			NumSkySamples	= 12
		;

		/* Debugging */
		enum class DebugMode {
			Off,
			Tiles,
			Checker,
			Positions,
			Normals,
		};
		constexpr DebugMode Debug = DebugMode::Off;

		constexpr float
			PointScale		= 7500.f * 2.f,
			ThreshIgnore	= 2.f,
			SurfaceBias		= 4.f,
			SkyRayLength	= 8192.f
		;

		/* Metadata */
		constexpr auto
			Descriptor		= Texture::Descriptors[Texture::Lightmap];

		constexpr u16
			Width			= Descriptor.width,
			Height			= Descriptor.height
		;

		////////////////////////////////////////////////////////////////

		u32 PackVec3(const vec3& v) {
			return 
				clamp((i32)floor(v.x * 255.f + 0.5f), 0, 255) << 16 |
				clamp((i32)floor(v.y * 255.f + 0.5f), 0, 255) <<  8 |
				clamp((i32)floor(v.z * 255.f + 0.5f), 0, 255) <<  0 ;
		}
	} // namespace Lightmap
} // namespace Demo

////////////////////////////////////////////////////////////////

FORCEINLINE void Map::AllocLightmap() {
	using namespace Demo;

	lightmap.data = Mem::Alloc<u32>(Lightmap::Width * Lightmap::Height);
	lightmap.pos = Mem::Alloc<vec3>(Lightmap::Width * Lightmap::Height);
	lightmap.nor = Mem::Alloc<vec3>(Lightmap::Width * Lightmap::Height);
}

FORCEINLINE void Map::Details::PackLightmap() {
	using namespace Demo;

	MemSet(lightmap.pos, 0, Lightmap::Width * Lightmap::Height);
	MemSet(lightmap.nor, 0, Lightmap::Width * Lightmap::Height);

	lightmap.packer.Init(Lightmap::Width, Lightmap::Height);

	/* pack patches */
	for (u16 patch_index = 0; patch_index < patches.count; ++patch_index) {
		auto patch = source->GetPatch(patches.GetSourceIndex(patch_index));
		bool is_mirrored = patches.IsMirrored(patch_index);

		u16 num_control_points = patch.width * patch.height;

		const u16 MaxPatchVertices = 64;
		PackedMap::PatchVertex ctrl[MaxPatchVertices];

		assert(num_control_points <= MaxPatchVertices);
		for (u16 i = 0; i < num_control_points; ++i) {
			ctrl[i] = source->GetPatchVertex(patch, i + patches.control_start[patch_index]);
			if (is_mirrored) {
				ctrl[i].pos[symmetry_axis] = 2 * symmetry_level - ctrl[i].pos[symmetry_axis];
			}
		}

		vec2 size = 0.f;
		for (u16 j = 0; j < patch.height; j += 2) {
			const PackedMap::PatchVertex* row = ctrl + j * patch.width;
			float width = 0.f;
			for (u16 i = 2; i < patch.width; i += 2)
				width += length(row[i].pos - row[i - 2].pos);
			if (size.x < width)
				size.x = width;
		}

		for (u16 i = 0; i < patch.width; i += 2) {
			const PackedMap::PatchVertex* column = ctrl + i;
			float height = 0.f;
			for (u16 j = 2; j < patch.height; j += 2, column += 2 * patch.width)
				height += length(column[2 * patch.width].pos - column[0].pos);
			if (size.y < height)
				size.y = height;
		}

		size.x = ceil(size.x / Lightmap::TexelSize);
		size.y = ceil(size.y / Lightmap::TexelSize);

		auto tile = lightmap.packer.Add(u16(size.x) + 1, u16(size.y) + 1);
		assert(tile != lightmap.packer.Full);
		auto& rect = lightmap.packer.GetTile(tile);

		for (u16 vtx_index = patches.vertex_start[patch_index], vtx_end = vtx_index + patches.vertex_count[patch_index]; vtx_index < vtx_end; ++vtx_index) {
			vec2& lightmap_uv = texcoords[vtx_index].zw;
			lightmap_uv.x = (rect.min[0] + 0.5f + lightmap_uv.x * size.x) / Lightmap::Width;
			lightmap_uv.y = (rect.min[1] + 0.5f + lightmap_uv.y * size.y) / Lightmap::Height;
		}
		
		vec3* texel_pos = lightmap.pos + rect.min[1] * Lightmap::Width + rect.min[0];
		vec3* texel_nor = lightmap.nor + rect.min[1] * Lightmap::Width + rect.min[0];

		u8 prim_x = patch.width >> 1;
		u8 prim_y = patch.height >> 1;

		for (u16 y = 0, height = rect.GetHeight(); y < height; ++y, texel_pos += Lightmap::Width, texel_nor += Lightmap::Width) {
			float t = y * (prim_y / float(height - 1));
			i16 j = min((i16)floor(t), prim_y - 1);
			t -= j;
			j <<= 1;
			assert(j + 2 < patch.height);
			float t_coeff[3] = {(1.f - t) * (1.f - t), 2.f * t * (1.f - t), t * t};
			PackedMap::PatchVertex* row = ctrl + j * patch.width;

			for (u16 x = 0, width = rect.GetWidth(); x < width; ++x) {
				float s = x * (prim_x / float(width - 1));
				i16 i = min((i16)floor(s), prim_x - 1);
				s -= i;
				i <<= 1;
				assert(i + 2 < patch.width);
				float s_coeff[3] = {(1.f - s) * (1.f - s), 2.f * s * (1.f - s), s * s};

				vec3 v[3];
				auto* c = row + i;
				for (u16 k = 0; k < 3; ++k, c += patch.width) {
					v[k].x = s_coeff[0]*c[0].pos.x + s_coeff[1]*c[1].pos.x + s_coeff[2]*c[2].pos.x;
					v[k].y = s_coeff[0]*c[0].pos.y + s_coeff[1]*c[1].pos.y + s_coeff[2]*c[2].pos.y;
					v[k].z = s_coeff[0]*c[0].pos.z + s_coeff[1]*c[1].pos.z + s_coeff[2]*c[2].pos.z;
				}

				texel_pos[x].x = t_coeff[0]*v[0].x + t_coeff[1]*v[1].x + t_coeff[2]*v[2].x;
				texel_pos[x].y = t_coeff[0]*v[0].y + t_coeff[1]*v[1].y + t_coeff[2]*v[2].y;
				texel_pos[x].z = t_coeff[0]*v[0].z + t_coeff[1]*v[1].z + t_coeff[2]*v[2].z;

				vec3 dt = t_coeff[0] * (v[1] - v[0]) + t_coeff[2] * (v[2] - v[1]);

				c = row + i;
				for (u16 k = 0; k < 3; ++k, ++c) {
					v[k].x = t_coeff[0]*c[0].pos.x + t_coeff[1]*c[patch.width].pos.x + t_coeff[2]*c[patch.width*2].pos.x;
					v[k].y = t_coeff[0]*c[0].pos.y + t_coeff[1]*c[patch.width].pos.y + t_coeff[2]*c[patch.width*2].pos.y;
					v[k].z = t_coeff[0]*c[0].pos.z + t_coeff[1]*c[patch.width].pos.z + t_coeff[2]*c[patch.width*2].pos.z;
				}
				vec3 ds = s_coeff[0] * (v[1] - v[0]) + s_coeff[2] * (v[2] - v[1]);

				auto& nor = texel_nor[x];
				safe_normalize(cross(dt, ds), nor);
				
				u32 flip_sign = is_mirrored << 31;
				*(u32*)&nor[0] ^= flip_sign;
				*(u32*)&nor[1] ^= flip_sign;
				*(u32*)&nor[2] ^= flip_sign;
			}
		}
	}

	/* pack brush planes */
	for (u16 brush_index = 0; brush_index < brushes.count; ++brush_index) {
		u32 end_plane_index = brushes.start[brush_index + 1];
		for (u32 plane_index = brushes.start[brush_index]; plane_index < end_plane_index; ++plane_index) {
			auto material = brushes.GetPlaneMaterial(plane_index);
			auto props = Material::Properties[material];
			auto vis = props & Material::MaskVisibility;
			if (vis != Material::Opaque)
				continue;

			auto vtx_range = brushes.plane_vertex_range[plane_index];
			auto vtx_count = vtx_range.GetCount();
			if (vtx_count < 3)
				continue;
		
			auto vtx_offset = vtx_range.GetOffset();
			vec3* pos = positions + vtx_offset;
			vec4* uv = texcoords + vtx_offset;

			u8 uv_axis = brushes.GetPlaneUVAxis(plane_index);
			u8 s_axis = (uv_axis == 0);			// 1 0 0
			u8 t_axis = (uv_axis != 2) + 1;		// 2 2 1

			Rect uv_bounds;
			uv_bounds.clear();
			for (vec3 *v = pos, *endv = pos + vtx_count; v != endv; ++v)
				uv_bounds.add(vec2{(*v)[s_axis], (*v)[t_axis]});

			uv_bounds.mins.x = floor(uv_bounds.mins.x / Lightmap::TexelSize) - 0.5f;
			uv_bounds.mins.y = floor(uv_bounds.mins.y / Lightmap::TexelSize) - 0.5f;
			uv_bounds.maxs.x = ceil(uv_bounds.maxs.x / Lightmap::TexelSize) + 0.5f;
			uv_bounds.maxs.y = ceil(uv_bounds.maxs.y / Lightmap::TexelSize) + 0.5f;

			const vec4& plane = brushes.planes[plane_index];
			auto uv_unmap = [&](float s, float t) -> vec3 {
				s = (s + uv_bounds.mins.x + 0.5f) * Lightmap::TexelSize;
				t = (t + uv_bounds.mins.y + 0.5f) * Lightmap::TexelSize;

				vec3 pos;
				pos[s_axis ] = s;
				pos[t_axis ] = t;
				pos[uv_axis] = -(plane.w + s * plane[s_axis] + t * plane[t_axis]) / plane[uv_axis];

				if (0) {
					vec2 uv;
					uv.x = pos[s_axis] / Lightmap::TexelSize;
					uv.y = pos[t_axis] / Lightmap::TexelSize;

					assert(uv.x >= uv_bounds.mins.x);
					assert(uv.x <= uv_bounds.maxs.x);
					assert(uv.y >= uv_bounds.mins.y);
					assert(uv.y <= uv_bounds.maxs.y);
				}

				return pos;
			};

			auto tile = lightmap.packer.Add(u16(uv_bounds.width()), u16(uv_bounds.height()));
			assert(tile != lightmap.packer.Full);
			auto& rect = lightmap.packer.GetTile(tile);

			for (u16 vtx_index = 0; vtx_index < vtx_count; ++vtx_index) {
				vec2& lightmap_uv = uv[vtx_index].zw;
				vec3& p = pos[vtx_index];
				lightmap_uv.x = (p[s_axis] / Lightmap::TexelSize - uv_bounds.mins.x + rect.min[0]) / Lightmap::Width;
				lightmap_uv.y = (p[t_axis] / Lightmap::TexelSize - uv_bounds.mins.y + rect.min[1]) / Lightmap::Height;
			}

			vec3* texel_pos = lightmap.pos + rect.min[1] * Lightmap::Width + rect.min[0];
			vec3* texel_nor = lightmap.nor + rect.min[1] * Lightmap::Width + rect.min[0];
				
			for (u16 y = 0, height = rect.GetHeight(); y < height; ++y, texel_pos += Lightmap::Width, texel_nor += Lightmap::Width) {
				for (u16 x = 0, width = rect.GetWidth(); x < width; ++x) {
					vec3 pos = uv_unmap(x, y);

					if (0) {
						const float MaxBorder = Lightmap::TexelSize;

						float edge_dist = 0.f;
						for (u16 i = brushes.start[brush_index]; i < end_plane_index; ++i) {
							if (i == plane_index)
								continue;
							const vec4& other_plane = brushes.planes[i];
							assign_max(edge_dist, dot(other_plane.xyz, pos) + other_plane.w);
						}

						if (edge_dist > MaxBorder)
							continue;
					}

					texel_pos[x] = pos;
					texel_nor[x] = plane.xyz;
				}
			}
		}
	}
}

////////////////////////////////////////////////////////////////

namespace Details {
	namespace ParallelFor {
		struct Batch {
			u32 begin;
			u32 end;
			void* data;
			void (*work)(u32 begin, u32 end, void* data);
		};
	
		void Thunk(void* param) {
			Batch* batch = (Batch*)param;
			batch->work(batch->begin, batch->end, batch->data);
		};
	}
}

void ParallelFor(u32 count, void* data, void (*work)(u32 begin, u32 end, void* data)) {
	const u32 MAX_NUM_THREADS = 256; // should be enough for TR5

	u32 cpu_threads = Sys::GetNumCPUThreads();
	if (cpu_threads > MAX_NUM_THREADS)
		cpu_threads = MAX_NUM_THREADS;
	if (cpu_threads > count)
		cpu_threads = count;
	u32 batch_size = (count + cpu_threads - 1) / cpu_threads;

	using Batch		= Details::ParallelFor::Batch;
	Batch			batches[MAX_NUM_THREADS];
	Sys::Thread		workers[MAX_NUM_THREADS];

	for (u32 batch_index = 0, offset = 0; batch_index < cpu_threads; ++batch_index, offset += batch_size) {
		auto& batch = batches[batch_index];
		batch.begin = offset;
		batch.end = min(offset + batch_size, count);
		batch.data = data;
		batch.work = work;
		auto& thread = workers[batch_index];
		thread.work = Details::ParallelFor::Thunk;
		thread.data = &batch;
		Sys::SpawnThread(thread);
	}

	for (u32 batch_index = 0; batch_index < cpu_threads; ++batch_index)
		Sys::JoinThread(workers[batch_index]);
}

FORCEINLINE void ComputeTangentFrame(const vec3& z, vec3& x, vec3& y) {
	// find normal component with smallest magnitude
	vec3 abs_z = abs(z);
	int next_axis = 0;
	if (abs_z[1] < abs_z[0])
		next_axis = 1;
	if (abs_z[2] < abs_z[next_axis])
		next_axis = 2;

	// setup tangent frame
	MemSet(&x);
	x[next_axis] = 1.f;
	cross(z, x, y);
	normalize(y);
	cross(z, y, x);
}

// http://extremelearning.com.au/unreasonable-effectiveness-of-quasirandom-sequences/
namespace R2 {
	static constexpr float
		G = 1.324718,
		X = 1.f / G,
		Y = 1.f / (G * G);

	struct CosineHemisphere {
		float u = 0.5f;
		float v = Math::PI;

		vec3 NextSample() {

			float cos_theta = sqrt(1.f - fract(u));
			float sin_theta = sqrt(1.f - cos_theta * cos_theta);
			float phi = v;

			u += R2::X;
			v += R2::Y * Math::TAU;

			return {
				sin_theta * cos(phi),
				sin_theta * sin(phi),
				cos_theta
			};
		}
	};
} // namespace R2

void Map::ComputeLighting(bool shadows) {
	using namespace Demo;

#ifdef DEV
	shadows = false;
#endif

	if constexpr (Lightmap::Debug == Lightmap::DebugMode::Off) {
		struct Params {
			bool shadows;
		} params{shadows};

		ParallelFor(Lightmap::Height, &params, [](u32 y, u32 yend, void* data) {
			Params* params = (Params*)data;

			u32* texel = Map::lightmap.data + y * Lightmap::Width;
			vec3* texel_pos = Map::lightmap.pos + y * Lightmap::Width;
			vec3* texel_nor = Map::lightmap.nor + y * Lightmap::Width;

			TraceInfo trace;
			MemSet(&trace);
			trace.type = TraceInfo::Type::Lightmap;
			// prevent the ray from squeezing between diagonally-adjacent brushes
			// this fixes a sun light leak in the left hallway of DM1
			trace.box_half_size = 1.f/32.f;

			TraceInfo occlusion_trace;
			if constexpr (Lightmap::JitterOccluded) {
				MemCopy(&occlusion_trace, &trace);
			}

			for (; y < yend; ++y) {
				for (u16 x = 0; x < Lightmap::Width; ++x, ++texel_pos, ++texel_nor, ++texel) {
					vec3 pos = *texel_pos;
					const vec3& nor = *texel_nor;

					constexpr vec3 Ambient = {
						2.f * 6.25f,
						2.f * 6.25f,
						2.f * 7.f,
					};
					vec3 accum = Ambient;

					if (length_squared(nor) > 0.f) {
						vec3 x_axis, y_axis;
						ComputeTangentFrame(nor, x_axis, y_axis);

						if constexpr (Lightmap::JitterOccluded) {
							occlusion_trace.start = pos + nor;
							occlusion_trace.delta = nor;

							if (Map::TraceRay(occlusion_trace)) {
								const u16 Divs = 2;
								const float
									Scale =  Lightmap::TexelSize / float(Divs),
									Bias  = -Lightmap::TexelSize * (0.5f - 0.5f / Divs)
								;

								for (u16 i = 0; i < Divs * Divs; ++i) {
									vec3 offset = nor;
									mad(offset, x_axis, (i % Divs) * Scale + Bias);
									mad(offset, y_axis, (i / Divs) * Scale + Bias);

									occlusion_trace.start.x = pos.x + offset.x;
									occlusion_trace.start.y = pos.y + offset.y;
									occlusion_trace.start.z = pos.z + offset.z;

									if (!Map::TraceRay(occlusion_trace)) {
										pos = occlusion_trace.start;
										break;
									}
								}
							}
						}

						for (u16 light_index = 0; light_index < Map::num_lights; ++light_index) {
							const auto& light = Map::lights[light_index];
							vec3 light_pos = light.position;
							if (light_index == 0)
								light_pos += pos;

							vec3 light_dir = pos - light_pos;
							float angle = -dot(nor, light_dir);
							if (angle < 0.f)
								continue;

							float dist = length(light_dir);
							if (dist > 0.f)
								angle /= dist;
							assign_max(dist, 16.f);

							float scale = light.intensity * angle;
							if (light_index != 0)
								scale *= Lightmap::PointScale / (dist * dist);
							if (scale < Lightmap::ThreshIgnore)
								continue;

							if (light.flags & Light::IsSpotlight) {
								if (!EnableSpotlights)
									continue;
								float dist_by_normal = dot(light_dir, light.spot.xyz);
								if (dist_by_normal < 0.f)
									continue;

								const float Radius = 64.f;
								float radius_by_dist = (Radius + 16.f) / light.spot.w;
								float radius_at_dist = radius_by_dist * dist_by_normal;
								vec3 point_at_dist = light.position;
								mad(point_at_dist, light.spot.xyz, dist_by_normal);
								float sample_radius = length(pos - point_at_dist);
								if (sample_radius >= radius_at_dist)
									continue;

								if (sample_radius > radius_at_dist - 32.f)
									scale *= (radius_at_dist - sample_radius) * (1.f/32.f);
							}

							if (params->shadows) {
								// offset sampling point towards the light
								vec3 delta = light_pos - pos;
								float dist = length(delta);
								float bias = Lightmap::SurfaceBias / dist;
								trace.start.x = pos.x + delta.x * bias;
								trace.start.y = pos.y + delta.y * bias;
								trace.start.z = pos.z + delta.z * bias;
								trace.delta.x = light_pos.x - trace.start.x;
								trace.delta.y = light_pos.y - trace.start.y;
								trace.delta.z = light_pos.z - trace.start.z;

								if (Map::TraceRay(trace))
									continue;
							}

							mad(accum, light.color, scale);
						}

						if (source->skylight && params->shadows) {
							vec3 skylight;
							skylight.r = ((source->skylight      ) & 255) / float(Lightmap::NumSkySamples);
							skylight.g = ((source->skylight >>  8) & 255) / float(Lightmap::NumSkySamples);
							skylight.b = ((source->skylight >> 16) & 255) / float(Lightmap::NumSkySamples);

							R2::CosineHemisphere hemisphere;
							for (u16 i = 0; i < Lightmap::NumSkySamples; ++i) {
								trace.start.x = pos.x + nor.x;
								trace.start.y = pos.y + nor.y;
								trace.start.z = pos.z + nor.z;

								vec3 dir = hemisphere.NextSample();

								mul(trace.delta, x_axis, Lightmap::SkyRayLength * dir.x);
								mad(trace.delta, y_axis, Lightmap::SkyRayLength * dir.y);
								mad(trace.delta, nor,    Lightmap::SkyRayLength * dir.z);

								if (!Map::TraceRay(trace))
									accum += skylight;
							}
						}
					}

					// maintain hue instead of clamping to white
					float max_value = max_component(accum);
					if (max_value > 255.f)
						accum *= 255.f / max_value;

					u32 color = 
						min((i32)accum.x, 255) << 16 | 
						min((i32)accum.y, 255) <<  8 | 
						min((i32)accum.z, 255) <<  0 ;
					
					if (length_squared(nor) > 0.f)
						color |= 0xff00'0000;

					*texel = color;
				}
			}
		});

		if (Lightmap::Dilate) {
			for (u16 tile_index = 0, tile_count = lightmap.packer.GetNumTiles(); tile_index < tile_count; ++tile_index) {
				auto& rect = lightmap.packer.GetTile(tile_index);
				/* propagate right/down */
				u32* texel = lightmap.data + rect.min[1] * Lightmap::Width;
				for (u16 y = rect.min[1]; y < rect.max[1]; ++y, texel += Lightmap::Width) {
					for (u16 x = rect.min[0]; x < rect.max[0]; ++x) {
						if (x > rect.min[0] && !(texel[x] >> 24))
							texel[x] = texel[x - 1];
						if (y > rect.min[1] && !(texel[x] >> 24))
							texel[x] = texel[x - Lightmap::Width];
					}
				}
				/* propagate left/up */
				texel = lightmap.data + (rect.max[1] - 1) * Lightmap::Width;
				for (u16 y = rect.max[1]; y > rect.min[1]; --y, texel -= Lightmap::Width) {
					for (u16 x = rect.max[0]; x > rect.min[0]; --x) {
						if (x < rect.max[0] && !(texel[x - 1] >> 24))
							texel[x - 1] = texel[x];
						if (y < rect.max[1] && !(texel[x - 1] >> 24))
							texel[x - 1] = texel[x + Lightmap::Width - 1];
					}
				}
			}
		}
	} else {
		// fill lightmap with debug info (see Lightmap::Debug)

		for (u16 tile_index = 0, tile_count = lightmap.packer.GetNumTiles(); tile_index < tile_count; ++tile_index) {
			auto& rect = lightmap.packer.GetTile(tile_index);

			u32* texel = lightmap.data + rect.min[1] * Lightmap::Width;
			vec3* texel_pos = lightmap.pos + rect.min[1] * Lightmap::Width;
			vec3* texel_nor = lightmap.nor + rect.min[1] * Lightmap::Width;

			for (u16 y = rect.min[1]; y < rect.max[1]; ++y, texel += Lightmap::Width, texel_pos += Lightmap::Width, texel_nor += Lightmap::Width) {
				for (u16 x = rect.min[0]; x < rect.max[0]; ++x) {
					switch (Lightmap::Debug) {
						case Lightmap::DebugMode::Tiles:
							texel[x] = tile_index * 0x45d9f3b;
							break;

						case Lightmap::DebugMode::Checker:
							texel[x] = (x ^ y) & 1 ? 0xffff'ffff : 0x3f3f'3f3f;
							break;

						case Lightmap::DebugMode::Positions:
							texel[x] = Lightmap::PackVec3({
								fract(texel_pos[x].x / 64.f),
								fract(texel_pos[x].y / 64.f),
								fract(texel_pos[x].z / 64.f)
							});
							break;

						case Lightmap::DebugMode::Normals:
							texel[x] = Lightmap::PackVec3(texel_nor[x] * 0.5f + 0.5f);
							break;

						default:
							texel[x] = 0xFF00FF;
							break;
					}
				}
			}
		}
	}
}

FORCEINLINE void Map::UpdateLightmapTexture() {
	Gfx::SetTextureContents(Demo::Texture::Lightmap, lightmap.data);
#ifdef SAVE_LIGHTMAP
	Gfx::SaveTGA("lightmap.tga", Demo::Texture::Lightmap);
#endif
}
