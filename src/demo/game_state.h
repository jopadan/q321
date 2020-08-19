#pragma once

namespace Demo {
	Sys::Thread				g_loading_thread;
	bool					g_updated_lightmap;
	Sys::Time				g_level_time;
	Sys::Time				g_time;
	float					g_delta_time;

	FORCEINLINE bool IsLoading() {
		return !Sys::IsThreadReady(g_loading_thread);
	}

	void GenerateLightmap(void*) {
		g_updated_lightmap = false;
		Map::ComputeLighting(Map::LightMode::Shadows);
#ifdef ENABLE_RADIOSITY
		if (r_bounce.integer)
			Map::ComputeLighting(Map::LightMode::Bounce);
#endif
	}

	NOINLINE void LoadMap(Map::ID id) {
		Map::Load(id);
		Map::UpdateLightmapTexture();

		g_updated_lightmap = false;
		g_loading_thread.work = &GenerateLightmap;
		Sys::SpawnThread(Demo::g_loading_thread);

		Demo::g_player.Spawn();
	}

	FORCEINLINE void LoadNextMap() {
		Map::ID next_map = Map::ID((u8(Map::current_id) + 1) % u8(Map::ID::Count));
		LoadMap(next_map);
	}
}