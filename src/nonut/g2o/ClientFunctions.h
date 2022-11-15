#pragma once
#ifndef CLIENT_FUNCTIONS_H
#define CLIENT_FUNCTIONS_H
#include "nonut/Function.h"

#define CLIENT_FUNCTIONS nonut::g2o::ClientFunctions::GetInstance()

namespace nonut::g2o
{
	class ClientFunctions
	{
	protected:
		ClientFunctions();
		static ClientFunctions* instance;
	public:
		ClientFunctions(ClientFunctions& other) = delete;
		void operator=(const ClientFunctions&) = delete;
		static ClientFunctions* GetInstance();

		// G2O functions
		Function<void, std::string> print;

		// Chat input
		Function<void> chatInputClear;
		Function<void> chatInputClose;
		Function<std::string> chatInputGetFont;
		//Function < {x,y} > chatInputGetPosition;
		Function<std::string> chatInputGetText;
		Function<bool> chatInputIsOpen;
		Function<void> chatInputOpen;
		Function<void> chatInputSend;
		Function<void, std::string> chatInputSetFont;
		Function<void, int, int> chatInputSetPosition;
		Function<void, std::string> chatInputSetText;

		// Game
		Function<void> clearMultiplayerMessages;
		Function<void, bool> enableEvent_Render;
		Function<void, bool> enableEvent_RenderFocus;
		Function<void, bool> enable_DamageAnims;
		Function<void, bool> enable_NicknameId;
		Function<void, bool> enable_WeaponTrail;
		Function<void> exitGame;
		Function<float> getDayLength;
		Function<int> getFpsRate;
		Function<float> getLODStrengthModifier;
		Function<float> getLODStrengthOverride;
		//Function<{packetReceived, packetlossTotal, packetlossLastSecond,
		//			messagesInResendBuffer, messageInSendBuffer, bytesInResendBuffer,
		//			bytesInSendBuffer}> getNetworkStats;
		Function<float> getSightFactor;
		//Function< {day, hour, min} > getTime;
		//Function<int, userpointer> getVobType;
		Function<bool, std::string> playVideo;
		Function<void, int> setBloodMode;
		Function<void, float> setDayLength;
		Function<void, float> setLODStrengthModifier;
		Function<void, float> setLODStrengthOverride;
		Function<void, float> setSightFactor;
		Function<void, int, int, int> setTime;
		Function<void, bool> showPlayerStatus;
		Function<void, int> switchInterpolation;

		// Hash
		Function<std::string, std::string> fileMd5;

		// Hero
		Function<int> getExp;
		Function<int> getFocusNpc;
		Function<int> getGuildId;
		Function<std::string> getGuildName;
		Function<int> getLearnPoints;
		Function<int> getLevel;
		Function<int> getNextLevelExp;
		Function<int> getPingLimit;
		Function<bool> isFrozen;
		Function<bool> isInWater;
		Function<void, int> setExp;
		Function<void, bool> setFreeze;
		Function<void, int> setGuild;
		Function<void, int> setLearnPoints;
		Function<void, int> setLevel;
		Function<void, int> setNextLevelExp;
		Function<void, int> setPingLimit;

		// Input
		Function<void, bool> disableControls;
		Function<void, int, bool> disableKey;
		Function<void, int, bool> disableLogicalKey;
		[[deprecated]] Function<void, bool> enableKeys;
		Function<int> getKeyLayout;
		Function<std::string, int> getKeyLetter;
		//Function< ??? , int> getLogicalKeyBinding;
		Function<bool> isControlsDisabled;
		Function<bool, int> isKeyDisabled;
		Function<bool, int> isKeyPressed;
		Function<bool, int> isKeyToggled;
		[[deprecated]] Function<bool> isKeysEnabled;
		Function<bool, int> isLogicalKeyDisabled;
		Function<bool, int> isLogicalKeyPressed;
		Function<bool, int> isMouseBtnPressed;
		Function<void, int> resetLogicalKeys;
		Function<void> saveLogicalKeys;
		Function<void, std::string> setClipboardText;
		Function<void, int> setKeyLayout;
		//Function<void, int, array?> setLogicalKeyBinding;

		// Interface
		Function<int, int> anx;
		Function<int, int> any;
		//Function < {x, y, bpp} ... > getAvailableResolutions;
		//Function < {x, y}, int > getBarPosition;
		//Function < {width, height}, int > getBarSize;
		//Function < {x, y} > getCursorPosition;
		//Function < {x, y} > getCursorPositionPx;
		Function<float> getCursorSensitivity;
		//Function < {width, height} > getCursorSize;
		//Function < {width, height} > getCursorSizePx;
		Function<std::string> getCursorTxt;
		Function<int, int> getHudMode;
		//Function < {x, y, bpp} > getResolution;
		Function<bool> isConsoleOpen;
		Function<bool> isCursorVisible;
		Function<int> letterDistance;
		Function<int> letterHeight;
		Function<int> letterHeightPx;
		Function<int, std::string> letterWidth;
		Function<int, std::string> letterWidthPx;
		Function<int, int> nax;
		Function<int, int> nay;
		Function<void, int, int, int> setBarPosition;
		Function<void, int, int> setBarSize;
		Function<void, int, int> setCursorPosition;
		Function<void, int, int> setCursorPositionPx;
		Function<void, float> setCursorSensitivity;
		Function<void, int, int> setCursorSize;
		Function<void, int, int> setCursorSizePx;
		Function<void, std::string> setCursorTxt;
		Function<void, bool> setCursorVisible;
		Function<void, int, int> setHudMode;
		Function<bool, int, int, int> setResolution;
		Function<std::string> textGetFont;
		Function<void, std::string> textSetFont;
		Function<int, std::string> textWidth;
		Function<int, std::string> textWidthPx;

		// Inventory
		Function<void> clearInventory;
		Function<void> closeInventory;
		Function<int> getCurrentInventorySlot;
		//Function < {instance, amount, name}... > getEq;
		//Function < {instance, amount, name}, int > getItemBySlot;
		Function<int, int> hasItem;
		Function<bool> isInventoryOpen;
		Function<void> openInventory;

		// Item
		Function<std::string, std::string> getItemDescription;
		// getItemInfo deprecated
		Function<std::string, std::string> getItemName;
		Function<std::string, std::string> getItemValue;

		// Music
		Function<void, bool> disableMusicSystem;
		Function<float> getMusicVolume;
		Function<float> getSoundVolume;
		Function<bool> isMusicSystemDisabled;
		Function<void, float> setMusicVolume;
		Function<void, float> setSoundVolume;

		// NPC
		Function<int, std::string> createNpc;
		Function<bool, int> destroyNpc;
		Function<bool, int, std::string> spawnNpc;
		Function<bool, int> unspawnNpc;

		// Player
		Function<bool, int, std::string> addEffect;
		Function<bool, int, int> applyPlayerOverlay;
		Function<bool, int, int, int> attackPlayer;
		Function<bool, int, int, int> attackPlayerMagic;
		Function<bool, int, int> attackPlayerRanged;
		Function<void, int, int, int, int, bool, int, std::string> attackPlayerWithEffect;
		Function<void, int, int> drawWeapon;
		[[deprecated]] Function<bool, int, int> equipArmor;
		[[deprecated]] Function<bool, int, int> equipHelmet;
		[[deprecated]] Function<bool, int, int, int> equipItem;
		[[deprecated]] Function<bool, int, int> equipMeleeWeapon;
		[[deprecated]] Function<bool, int, int> equipShield;
		Function<int, int> getActFrame;
		Function<std::string, int> getFaceAniName;
		Function<int, int> getLastHitAniFrame;
		Function<int, int> getPlayerAmulet;
		Function<float, int> getPlayerAngle;
		Function<std::string, int> getPlayerAni;
		Function<int, int> getPlayerAniId;
		Function<int, int, std::string> getPlayerAniIdByName;
		Function<std::string, int, int> getPlayerAniNameById;
		Function<int, int> getPlayerArmor;
		//Function<Vec3, int> getPlayerAtVector;
		Function<int, int> getPlayerBelt;
		Function<bool, int> getPlayerCollision;
		//Function < {r, g, b}, int > getPlayerColor;
		Function<int, int> getPlayerDexterity;
		Function<float, int> getPlayerFatness;
		Function<int, int> getPlayerHealth;
		Function<int, int> getPlayerHelmet;
		//Function<int, userpointer> getPlayerIdByPtr;
		Function<std::string, int> getPlayerInstance;
		Function<int, int> getPlayerMagicLevel;
		Function<int, int> getPlayerMana;
		//Function<Mat4, int> getPlayerMatrix;
		Function<int, int> getPlayerMaxHealth;
		Function<int, int> getPlayerMaxMana;
		Function<int, int> getPlayerMeleeWeapon;
		Function<std::string, int> getPlayerName;
		Function<int, int> getPlayerPing;
		//Function < {x, y, z}, int > getPlayerPosition;
		Function<int, int, int> getPlayerProtection;
		//Function<userpointer, int> getPlayerPtr;
		Function<int, int> getPlayerRangedWeapon;
		Function<int, int> getPlayerReadiedWeapon;
		Function<int, int, int> getPlayerRing;
		//Function < {x, y, z}, int > getPlayerScale;
		Function<int, int> getPlayerShield;
		Function<int, int, int> getPlayerSkillWeapon;
		Function<int, int, int> getPlayerSpell;
		Function<int, int> getPlayerStrength;
		Function<void, int, int, bool> getPlayerTalent; // SUS
		Function<int, int> getPlayerType;
		//Function < {bodyModel, bodyTxt, headModel, headTxt}, int > getPlayerVisual;
		Function<float, int> getPlayerVisualAlpha;
		Function<int, int> getPlayerWeaponMode;
		Function<void, int, int, int> giveItem;
		Function<bool, int, int> hitPlayer;
		Function<bool, int> isPlayerCreated;
		Function<bool, int> isPlayerDead;
		Function<bool, int> isPlayerInWater;
		Function<bool, int> isPlayerStreamed;
		Function<bool, int> isPlayerUnconscious;
		Function<void, int, std::string> playAni;
		Function<void, int, int> playAniId;
		Function<void, int> playGesticulation;
		Function<void, int, int, int> readySpell;
		Function<bool, int, std::string> removeEffect;
		Function<void, int, int, int> removeItem;
		Function<bool, int, int> removePlayerOverlay;
		Function<void, int> removeWeapon;
		Function<void, int, float> setPlayerAngle;
		Function<void, int, bool> setPlayerCollision;
		Function<void, int, int, int, int> setPlayerColor;
		Function<void, int, int> setPlayerDexterity;
		Function<void, int, float> setPlayerFatness;
		Function<void, int, int> setPlayerHealth;
		Function<void, int, std::string> setPlayerInstance;
		Function<void, int, int> setPlayerMagicLevel;
		Function<void, int, int> setPlayerMana;
		Function<void, int, int> setPlayerMaxHealth;
		Function<void, int, int> setPlayerMaxMana;
		Function<void, int, std::string> setPlayerName;
		Function<void, int> setPlayerOnFloor;
		Function<void, int, float, float, float> setPlayerPosition;
		Function<void, int, float, float, float> setPlayerScale;
		Function<void, int, int, int> setPlayerSkillWeapon;
		Function<void, int, int> setPlayerStrength;
		Function<void, int, int, bool> setPlayerTalent;
		Function<void, int, int, std::string, int> setPlayerVisual;
		Function<bool, int, float> setPlayerVisualAlpha;
		Function<void, int, int> setPlayerWeaponMode;
		Function<bool, int, std::string> startFaceAni;
		Function<void, int, std::string> stopAni;
		Function<void, int, int> stopAniId;
		Function<bool, int> stopFaceAni;
		[[deprecated]] Function<void, int> unequipArmor;
		[[deprecated]] Function<void, int> unequipHelmet;
		Function<bool, int, int> unequipItem;
		[[deprecated]] Function<void, int> unequipMeleeWeapon;
		[[deprecated]] Function<void, int> unequipRangedWeapon;
		[[deprecated]] Function<void, int> unequipShield;
		Function<void, int> unreadySpell;
		Function<void, int, std::string, int> useClosestMob;
		Function<void, int, int, int> useItem;

		// World
		Function<void, std::string, std::string> changeWorld;
		Function<std::string> getWorld;
	};
}
#endif
