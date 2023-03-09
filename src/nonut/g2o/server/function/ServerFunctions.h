#ifndef NONUT_G2O_SERVER_FUNCTION_SERVER_FUNCTIONS_H
#define NONUT_G2O_SERVER_FUNCTION_SERVER_FUNCTIONS_H
#include "Function.h"
#include "CustomTypes.h"
#include "class/math/Mat4.h"

#define SERVER_FUNCTIONS nonut::g2o::ServerFunctions::getInstance()
#define S_F SERVER_FUNCTIONS

namespace nonut::g2o
{
	class ServerFunctions
	{
	protected:
		ServerFunctions();
		static inline ServerFunctions* instance = nullptr;
	public:
		ServerFunctions(ServerFunctions& other) = delete;
		void operator=(const ServerFunctions&) = delete;
		static ServerFunctions* getInstance();

		// G2O functions

		// Chat
		Function<void, Int, Int, Int, String> sendMessageToAll;
		Function<void, Int, Int, Int, Int, String> sendMessageToPlayer;
		Function<void, Int, Int, Int, Int, String> sendPlayerMessageToAll;
		Function<void, Int, Int, Int, Int, Int, String> sendPlayerMessageToPlayer;

		// Game
		Function<void> abort;
		Function<void, Bool> enableEvent_onTick;
		Function<void, Int> exit;
		Function<Float> getDayLength;
		Function<String> getServerDescription;
		Function<String> getServerWorld;
		Function<GameTime> getTime;
		Function<void, Float> setDayLength;
		Function<void, String> setServerDescription;
		Function<void, String> setServerWorld;
		Function<void, Int, Int, Int> setTime;

		// Player
		Function<Bool, Int, Int> applyPlayerOverlay;
		Function<void, Int, Int, String> ban;
		Function<void, Int, Int> equipArmor;
		Function<void, Int, Int> equipHelmet;
		Function<void, Int, Int, Int> equipItem;
		Function<void, Int, Int> equipMeleeWeapon;
		Function<void, Int, Int> equipRangedWeapon;
		Function<void, Int, Int> equipShield;
		Function<void, Int, Int, Int> equipSpell;
		Function<String, Int> getFaceAniName;
		Function<Int, Int> getPlayerAmulet;
		Function<Float, Int> getPlayerAngle;
		Function<Int, Int> getPlayerAniId;
		Function<Int, Int> getPlayerArmor;
		Function<Vec3, Int> getPlayerAtVector;
		Function<Int, Int> getPlayerBelt;
		Function<Vec3, Int> getPlayerCameraPosition;
		Function<Bool, Int> getPlayerCollision;
		Function<Color, Int> getPlayerColor;
		Function<Int, Int> getPlayerDexterity;
		Function<Float, Int> getPlayerFatness;
		Function<Int> getPlayerFocus;
		Function<Int, Int> getPlayerHealth;
		Function<Int, Int> getPlayerHelmet;
		Function<String, Int> getPlayerIP;
		Function<String, Int> getPlayerInstance;
		Function<Bool, Int> getPlayerInvisible;
		Function<String, Int> getPlayerMacAddr;
		Function<Int, Int> getPlayerMagicLevel;
		Function<Int, Int> getPlayerMana;
		Function<Int, Int> getPlayerMaxHealth;
		Function<Int, Int> getPlayerMaxMana;
		Function<Int, Int> getPlayerMeleeWeapon;
		Function<String, Int> getPlayerName;
		Function<Int, Int> getPlayerPing;
		Function<Position3d, Int> getPlayerPosition;
		Function<Int, Int> getPlayerRangedWeapon;
		Function<String, Int> getPlayerRespawnTime;
		Function<Int, Int, Int> getPlayerRing;
		Function<Position3d, Int> getPlayerScale;
		Function<Int, Int> getPlayerSerial;
		Function<Int, Int> getPlayerShield;
		Function<Int, Int, Int> getPlayerSkillWeapon;
		Function<Int, Int, Int> getPlayerSpell;
		Function<Int, Int> getPlayerStrength;
		Function<Bool, Int, Int> getPlayerTalent;
		Function<Int, Int> getPlayerVirtualWorld;
		Function<BodyVisual, Int> getPlayerVisual;
		Function<Int, Int> getPlayerWeaponMode;
		Function<String, Int> getPlayerWorld;
		Function<void, Int, Int, Int> giveItem;
		Function<Bool, Int> isPlayerConnected;
		Function<Bool, Int> isPlayerDead;
		Function<Bool, Int> isPlayerSpawned;
		Function<Bool, Int> isPlayerUnconscious;
		Function<void, Int, String> kick;
		Function<void, Int, String> playAni;
		Function<void, Int, Int> playAniId;
		Function<void, Int, Int, Int> removeItem;
		Function<Bool, Int, Int> removePlayerOverlay;
		Function<void, Int, Float> setPlayerAngle;
		Function<void, Int, Bool> setPlayerCollision;
		Function<void, Int, Int, Int, Int> setPlayerColor;
		Function<void, Int, Int> setPlayerDexterity;
		Function<void, Int, Float> setPlayerFatness;
		Function<void, Int, Int> setPlayerHealth;
		Function<void, Int, String> setPlayerInstance;
		Function<void, Int, Bool> setPlayerInvisible;
		Function<void, Int, Int> setPlayerMagicLevel;
		Function<void, Int, Int> setPlayerMana;
		Function<void, Int, Int> setPlayerMaxHealth;
		Function<void, Int, Int> setPlayerMaxMana;
		Function<Bool, Int, String> setPlayerName;
		Function<void, Int, Float, Float, Float> setPlayerPosition;
		Function<void, Int, Int> setPlayerRespawnTime;
		Function<void, Int, Float, Float, Float> setPlayerScale;
		Function<void, Int, Int, Int> setPlayerSkillWeapon;
		Function<void, Int, Int> setPlayerStrength;
		Function<void, Int, Int, Bool> setPlayerTalent;
		Function<void, Int, Int> setPlayerVirtualWorld;
		Function<void, Int, Int, String, Int> setPlayerVisual;
		Function<void, Int, Int> setPlayerWeaponMode;
		Function<void, Int, String, String> setPlayerWorld;
		Function<void, Int> spawnPlayer;
		Function<void, Int, String> startFaceAni;
		Function<void, Int, String> stopAni;
		Function<void, Int, Int> stopAniId;
		Function<void, Int> stopFaceAni;
		Function<void, Int> unequipArmor;
		Function<void, Int> unequipHelmet;
		Function<void, Int, Int> unequipItem;
		Function<void, Int> unequipMeleeWeapon;
		Function<void, Int> unequipRangedWeapon;
		Function<void, Int> unequipShield;
		Function<void, Int> unspawnPlayer;
		Function<void, Int, Int, Int> useItem;

		// Waypoint
		Function<Position3dWithName, Int, Int, Int> getNearestWaypoint;
		Function<Position3d, String, String> getWaypoint;
		
	};
}
#endif // NONUT_G2O_SERVER_FUNCTION_SERVER_FUNCTIONS_H
