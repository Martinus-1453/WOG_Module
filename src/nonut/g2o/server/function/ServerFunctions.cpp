#include "ServerFunctions.h"

namespace nonut::g2o
{
	ServerFunctions::ServerFunctions():
		FUNCTION_CTOR(sendMessageToAll),
		FUNCTION_CTOR(sendMessageToPlayer),
		FUNCTION_CTOR(sendPlayerMessageToAll),
		FUNCTION_CTOR(sendPlayerMessageToPlayer),
		FUNCTION_CTOR(abort),
		FUNCTION_CTOR(enableEvent_onTick),
		FUNCTION_CTOR(exit),
		FUNCTION_CTOR(getDayLength),
		FUNCTION_CTOR(getServerDescription),
		FUNCTION_CTOR(getServerWorld),
		FUNCTION_CTOR(getTime),
		FUNCTION_CTOR(setDayLength),
		FUNCTION_CTOR(setServerDescription),
		FUNCTION_CTOR(setServerWorld),
		FUNCTION_CTOR(setTime),
		FUNCTION_CTOR(applyPlayerOverlay),
		FUNCTION_CTOR(ban),
		FUNCTION_CTOR(equipArmor),
		FUNCTION_CTOR(equipHelmet),
		FUNCTION_CTOR(equipItem),
		FUNCTION_CTOR(equipMeleeWeapon),
		FUNCTION_CTOR(equipRangedWeapon),
		FUNCTION_CTOR(equipShield),
		FUNCTION_CTOR(equipSpell),
		FUNCTION_CTOR(getFaceAniName),
		FUNCTION_CTOR(getPlayerAmulet),
		FUNCTION_CTOR(getPlayerAngle),
		FUNCTION_CTOR(getPlayerAniId),
		FUNCTION_CTOR(getPlayerArmor),
		FUNCTION_CTOR(getPlayerBelt),
		FUNCTION_CTOR(getPlayerCameraPosition),
		FUNCTION_CTOR(getPlayerCollision),
		FUNCTION_CTOR(getPlayerColor),
		FUNCTION_CTOR(getPlayerDexterity),
		FUNCTION_CTOR(getPlayerFatness),
		FUNCTION_CTOR(getPlayerFocus),
		FUNCTION_CTOR(getPlayerHealth),
		FUNCTION_CTOR(getPlayerHelmet),
		FUNCTION_CTOR(getPlayerIP),
		FUNCTION_CTOR(getPlayerInstance),
		FUNCTION_CTOR(getPlayerInvisible),
		FUNCTION_CTOR(getPlayerMacAddr),
		FUNCTION_CTOR(getPlayerMagicLevel),
		FUNCTION_CTOR(getPlayerMana),
		FUNCTION_CTOR(getPlayerMaxHealth),
		FUNCTION_CTOR(getPlayerMaxMana),
		FUNCTION_CTOR(getPlayerMeleeWeapon),
		FUNCTION_CTOR(getPlayerName),
		FUNCTION_CTOR(getPlayerPing),
		FUNCTION_CTOR(getPlayerPosition),
		FUNCTION_CTOR(getPlayerRangedWeapon),
		FUNCTION_CTOR(getPlayerRespawnTime),
		FUNCTION_CTOR(getPlayerRing),
		FUNCTION_CTOR(getPlayerScale),
		FUNCTION_CTOR(getPlayerSerial),
		FUNCTION_CTOR(getPlayerShield),
		FUNCTION_CTOR(getPlayerSkillWeapon),
		FUNCTION_CTOR(getPlayerSpell),
		FUNCTION_CTOR(getPlayerStrength),
		FUNCTION_CTOR(getPlayerTalent),
		FUNCTION_CTOR(getPlayerVirtualWorld),
		FUNCTION_CTOR(getPlayerVisual),
		FUNCTION_CTOR(getPlayerWeaponMode),
		FUNCTION_CTOR(getPlayerWorld),
		FUNCTION_CTOR(giveItem),
		FUNCTION_CTOR(isPlayerConnected),
		FUNCTION_CTOR(isPlayerDead),
		FUNCTION_CTOR(isPlayerSpawned),
		FUNCTION_CTOR(isPlayerUnconscious),
		FUNCTION_CTOR(kick),
		FUNCTION_CTOR(playAni),
		FUNCTION_CTOR(playAniId),
		FUNCTION_CTOR(removeItem),
		FUNCTION_CTOR(removePlayerOverlay),
		FUNCTION_CTOR(setPlayerAngle),
		FUNCTION_CTOR(setPlayerCollision),
		FUNCTION_CTOR(setPlayerColor),
		FUNCTION_CTOR(setPlayerDexterity),
		FUNCTION_CTOR(setPlayerFatness),
		FUNCTION_CTOR(setPlayerHealth),
		FUNCTION_CTOR(setPlayerInstance),
		FUNCTION_CTOR(setPlayerInvisible),
		FUNCTION_CTOR(setPlayerMagicLevel),
		FUNCTION_CTOR(setPlayerMana),
		FUNCTION_CTOR(setPlayerMaxHealth),
		FUNCTION_CTOR(setPlayerMaxMana),
		FUNCTION_CTOR(setPlayerName),
		FUNCTION_CTOR(setPlayerPosition),
		FUNCTION_CTOR(setPlayerRespawnTime),
		FUNCTION_CTOR(setPlayerScale),
		FUNCTION_CTOR(setPlayerSkillWeapon),
		FUNCTION_CTOR(setPlayerStrength),
		FUNCTION_CTOR(setPlayerTalent),
		FUNCTION_CTOR(setPlayerVirtualWorld),
		FUNCTION_CTOR(setPlayerVisual),
		FUNCTION_CTOR(setPlayerWeaponMode),
		FUNCTION_CTOR(setPlayerWorld),
		FUNCTION_CTOR(spawnPlayer),
		FUNCTION_CTOR(startFaceAni),
		FUNCTION_CTOR(stopAni),
		FUNCTION_CTOR(stopAniId),
		FUNCTION_CTOR(stopFaceAni),
		FUNCTION_CTOR(unequipArmor),
		FUNCTION_CTOR(unequipHelmet),
		FUNCTION_CTOR(unequipItem),
		FUNCTION_CTOR(unequipMeleeWeapon),
		FUNCTION_CTOR(unequipRangedWeapon),
		FUNCTION_CTOR(unequipShield),
		FUNCTION_CTOR(unspawnPlayer),
		FUNCTION_CTOR(useItem),
	{
	}

	ServerFunctions* ServerFunctions::getInstance()
	{
		if (instance == nullptr)
		{
			instance = new ServerFunctions();
		}
		return instance;
	}
}
