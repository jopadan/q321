#pragma once

#define DEMO_ENTITY_PROPERTIES(x)	\
	x(origin,			i16[3])		\
	x(light,			i16)		\
	x(spawnflags,		i16)		\
	x(target,			i16)		\
	x(targetname,		i16)		\
	x(angle,			i16)		\
	/*x(noise,			i16[3])*/	\
	x(model,			i16)		\
	x(_color,			i16)		\
	x(wait,				i16)		\
	x(random,			i16)		\
	/*x(music,			i16[3])*/	\
	/*x(message,		i16[3])*/	\
	/*x(ambient,		i16[3])*/	\
	x(dmg,				i16)		\

////////////////////////////////////////////////////////////////

#define DEMO_ENTITY_TYPES_WEAPONS(x)\
	/*Name							Description				Model								  R,   G,   B*/\
	x(weapon_rocketlauncher,		"Rocket launcher",		1 + Demo::Model::rocketl,			  0,   0,   0)\
	x(weapon_shotgun,				"Shotgun",				1 + Demo::Model::shotgun,			  0,   0,   0)\
	x(weapon_railgun,				"Railgun",				1 + Demo::Model::railgun,			  0,   0,   0)\
	x(weapon_plasmagun,				"Plasma Gun",			1 + Demo::Model::plasma,			  0,   0,   0)\

#define DEMO_ENTITY_TYPES_AMMO(x)\
	/*Name							Description				Model								  R,   G,   B*/\
	x(ammo_bullets,					"Bullets",				1 + Demo::Model::rocketam,			128, 112,   2)\
	x(ammo_rockets,					"Rockets",				1 + Demo::Model::rocketam,			128,   2,   2)\
	x(ammo_shells,					"Shells",				1 + Demo::Model::rocketam,			128,  64,   2)\
	x(ammo_slugs,					"Slugs",				1 + Demo::Model::rocketam,			  0,  80,  32)\
	x(ammo_cells,					"Cells",				1 + Demo::Model::rocketam,			112,   0,  64)\

#define DEMO_ENTITY_TYPES_HEALTH(x)\
	/*Name							Description				Model								  R,   G,   B*/\
	x(item_health,					"25 Health",			1 + Demo::Model::large_cross,		160, 128,  48)\
	x(item_health_large,			"50 Health",			1 + Demo::Model::large_cross,		144,  88,  56)\
	x(item_health_mega,				"Mega Health",			1 + Demo::Model::mega_cross,		  8, 119, 234)\

#define DEMO_ENTITY_TYPES_ARMOR(x)\
	/*Name							Description				Model								  R,   G,   B*/\
	x(item_armor_combat,			"Armor",				1 + Demo::Model::armor_red,			255, 255,   0)\
	x(item_armor_shard,				"Armor Shard",			1 + Demo::Model::shard,				 80,  88,  86)\
	x(item_armor_body,				"Heavy Armor",			1 + Demo::Model::armor_red,			255,   0,  16)\

#define DEMO_ENTITY_TYPES_POWERUPS(x)\
	/*Name							Description				Model								  R,   G,   B*/\
	x(item_quad,					"Quad Damage",			1 + Demo::Model::quad,				  8, 119, 234)\

#define DEMO_ENTITY_TYPES(x)		\
	/*Name							Description				Model								  R,   G,   B*/\
	x(worldspawn,					"",						0,									  0,   0,   0)\
	x(trigger_teleport,				"",						0,									  0,   0,   0)\
	x(trigger_multiple,				"",						0,									  0,   0,   0)\
	x(trigger_hurt,					"",						0,									  0,   0,   0)\
	x(trigger_push,					"",						0,									  0,   0,   0)\
	/*x(light,						"",						0,									  0,   0,   0)*/\
	x(target_position,				"",						0,									  0,   0,   0)\
	/*x(target_speaker,				"",						0,									  0,   0,   0)*/\
	x(misc_model,					"",						0,									  0,   0,   0)\
	x(info_player_deathmatch,		"",						0,									  0,   0,   0)\
	x(info_player_intermission,		"",						0,									  0,   0,   0)\
	x(misc_teleporter_dest,			"",						0,									  0,   0,   0)\
	DEMO_ENTITY_TYPES_AMMO(x)\
	DEMO_ENTITY_TYPES_WEAPONS(x)\
	DEMO_ENTITY_TYPES_HEALTH(x)\
	DEMO_ENTITY_TYPES_ARMOR(x)\
	DEMO_ENTITY_TYPES_POWERUPS(x)\
	x(target_remove_powerups,		"",						0,									  0,   0,   0)\

////////////////////////////////////////////////////////////////

namespace Demo {
	struct BaseEntity { // Only contains properties read from the map file
		enum class Type : i16 {
			#define PP_DEMO_ENTITY_TYPE_DECLARE(name,...)	name,
			DEMO_ENTITY_TYPES(PP_DEMO_ENTITY_TYPE_DECLARE)
			#undef PP_DEMO_ENTITY_TYPE_DECLARE

			Count,
		} type;

		enum {
			#define PP_DEMO_PROP_COUNT(name, type)			+sizeof(type)
			NumRawFields = (DEMO_ENTITY_PROPERTIES(PP_DEMO_PROP_COUNT)) / sizeof(i16) + 1, // +1 for entity type
			#undef PP_DEMO_PROP_COUNT
		};

		////////////////////////////////////////////////////////////////

		// since 'i16[3] origin;' is invalid, we use a helper alias
		template <typename T>
		using Field = T;

		#define PP_DEMO_PROP_DECLARE(name, type)			Field<type> name;
		DEMO_ENTITY_PROPERTIES(PP_DEMO_PROP_DECLARE)
		#undef PP_DEMO_PROP_DECLARE

		////////////////////////////////////////////////////////////////

		#define PP_ADD_ENTITY_TYPE_BIT(name, desc, ...)		+ (1 << (u32)Type::name)
		#define PP_ENTITY_TYPE_MASK(list)					list(PP_ADD_ENTITY_TYPE_BIT)

		static_assert(u32(Type::Count) <= 32, "Handle entity types >= 32");
		enum TypeMask : u32 {
			Ammo		= PP_ENTITY_TYPE_MASK(DEMO_ENTITY_TYPES_AMMO),
			Weapon		= PP_ENTITY_TYPE_MASK(DEMO_ENTITY_TYPES_WEAPONS),
			Health		= PP_ENTITY_TYPE_MASK(DEMO_ENTITY_TYPES_HEALTH),
			Armor		= PP_ENTITY_TYPE_MASK(DEMO_ENTITY_TYPES_ARMOR),
			Powerup		= PP_ENTITY_TYPE_MASK(DEMO_ENTITY_TYPES_POWERUPS),

			Pickup		= Ammo | Weapon | Health | Armor | Powerup,
		};

		#undef PP_ADD_ENTITY_TYPE_BIT
		#undef PP_ENTITY_TYPE_MASK

		static constexpr bool	IsWeapon(Type type)		{ return 0 != (TypeMask::Weapon & (1 << u32(type))); }
		constexpr bool			IsWeapon() const		{ return IsWeapon(type); }

		static constexpr bool	IsHealth(Type type)		{ return 0 != (TypeMask::Health & (1 << u32(type))); }
		constexpr bool			IsHealth() const		{ return IsHealth(type); }

		static constexpr bool	IsPickup(Type type)		{ return 0 != (TypeMask::Pickup & (1 << u32(type))); }
		constexpr bool			IsPickup() const		{ return IsPickup(type); }

		////////////////////////////////////////////////////////////////

		static constexpr float
			RespawnTimeAmmo		= 40.f,
			RespawnTimeWeapon	= 5.f,
			RespawnTimeHealth	= 35.f,
			RespawnTimeArmor	= 25.f,
			RespawnTimePowerup	= 120.f
		;

		static constexpr float GetRespawnTime(Type type) {
			u32 bit = 1 << u32(type);

			if (bit & TypeMask::Ammo)		return RespawnTimeAmmo;
			if (bit & TypeMask::Weapon)		return RespawnTimeWeapon;
			if (bit & TypeMask::Health)		return RespawnTimeHealth;
			if (bit & TypeMask::Armor)		return RespawnTimeArmor;
			if (bit & TypeMask::Powerup)	return RespawnTimePowerup;

			return 5.f;
		}
	};

	////////////////////////////////////////////////////////////////

	struct alignas(16) Entity : BaseEntity { // Adds data needed at runtime
		static constexpr float
			Radius				= 15.f,
			RespawnAnimTime		= 0.5f
		;

		enum : u32 {
			Version = Hash(
				#define PP_DEMO_HASH_ENTITY_TYPE(name, ...)			#name "*"
				#define PP_DEMO_HASH_ENTITY_FIELD(name, type)		#name "=" #type ";"

				DEMO_ENTITY_TYPES(PP_DEMO_HASH_ENTITY_TYPE)
				"/"
				DEMO_ENTITY_PROPERTIES(PP_DEMO_HASH_ENTITY_FIELD)

				#undef PP_DEMO_HASH_ENTITY_FIELD
				#undef PP_DEMO_HASH_ENTITY_TYPE
			)
		};

		float respawn;
		bool IsSpawned() const { return respawn < RespawnAnimTime; }
	};
}

