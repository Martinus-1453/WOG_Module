#ifndef NONUT_G2O_SHARED_CONSTANT_SHARED_CONSTANTS
#define NONUT_G2O_SHARED_CONSTANT_SHARED_CONSTANTS
#include "pch.h"

namespace nonut::g2o
{
	class SharedConstants
	{
	public:
		static void init();

		// constants Reliability

		static inline Int UNRELIABLE = 0;
		static inline Int UNRELIABLE_SEQUENCED = 0;
		static inline Int RELIABLE = 0;
		static inline Int RELIABLE_ORDERED = 0;
		static inline Int RELIABLE_SEQUENCED = 0;

		// constants Damage

		/// @brief Represents unknown damage type.
		static inline Int DAMAGE_UNKNOWN = 0;
		/// @brief Represents barrier damage type.
		static inline Int DAMAGE_BARRIER = 0;
		/// @brief Represents blunt (weapon) damage type.
		static inline Int DAMAGE_BLUNT = 0;
		/// @brief Represents edge/sharp (weapon) damage type.
		static inline Int DAMAGE_EDGE = 0;
		/// @brief Represents fire damage type.
		static inline Int DAMAGE_FIRE = 0;
		/// @brief Represents fly damage type.
		static inline Int DAMAGE_FLY = 0;
		/// @brief Represents magic damage type.
		static inline Int DAMAGE_MAGIC = 0;
		/// @brief Represents point (weapon) damage type.
		static inline Int DAMAGE_POINT = 0;
		/// @brief Represents fall damage type.
		static inline Int DAMAGE_FALL = 0;

		// constants General

		/// @brief true if parsed script is on client-side, otherwise false.
		static inline Int CLIENT_SIDE = 0;
		/// @brief true if parsed script is on server-side, otherwise false.
		static inline Int SERVER_SIDE = 0;

		// constants Hand

		/// @brief Represents npc left hand slot id.
		static inline Int HAND_LEFT = 0;
		/// @brief Represents npc right hand slot id.
		static inline Int HAND_RIGHT = 0;

		// constants Skill weapon
		/// @brief Represents npc one handed weapon skill.
		static inline Int WEAPON_1H = 0;
		/// @brief Represents npc two handed weapon skill.
		static inline Int WEAPON_2H = 0;
		/// @brief Represents npc bow weapon skill.
		static inline Int WEAPON_BOW = 0;
		/// @brief Represents npc crossbow weapon skill.
		static inline Int WEAPON_CBOW = 0;

		// constants Weapon mode

		/// @brief Represents npc none weapon mode.
		static inline Int WEAPONMODE_NONE = 0;
		/// @brief Represents npc fist weapon mode.
		static inline Int WEAPONMODE_FIST = 0;
		/// @brief Represents npc dagger weapon mode.
		static inline Int WEAPONMODE_DAG = 0;
		/// @brief Represents npc one handed weapon mode (melee weapon).
		static inline Int WEAPONMODE_1HS = 0;
		/// @brief Represents npc two handed weapon mode (melee weapon).
		static inline Int WEAPONMODE_2HS = 0;
		/// @brief Represents npc bow weapon mode (ranged weapon).
		static inline Int WEAPONMODE_BOW = 0;
		/// @brief Represents npc crossbow weapon mode (ranged weapon).
		static inline Int WEAPONMODE_CBOW = 0;
		/// @brief Represents npc magic weapon mode (spell).
		static inline Int WEAPONMODE_MAG = 0;
		/// @brief Represents npc maximum weapon mode (not actuall weapon mode, weapon modes count).
		static inline Int WEAPONMODE_MAX = 0;
	};
}
#endif // NONUT_G2O_SHARED_CONSTANT_SHARED_CONSTANTS
