#ifndef NONUT_G2O_CLIENT_FUNCTION_CLIENT_FUNCTIONS_H
#define NONUT_G2O_CLIENT_FUNCTION_CLIENT_FUNCTIONS_H
#include "Function.h"
#include "CustomTypes.h"

#define CLIENT_FUNCTIONS nonut::g2o::ClientFunctions::getInstance()

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
		static ClientFunctions* getInstance();

		// G2O functions

		// Chat input
		Function<void> chatInputClear;
		Function<void> chatInputClose;
		Function<String> chatInputGetFont;
		Function<Position2d> chatInputGetPosition;
		Function<String> chatInputGetText;
		Function<Bool> chatInputIsOpen;
		Function<void> chatInputOpen;
		Function<void> chatInputSend;
		Function<void, String> chatInputSetFont;
		Function<void, Int, Int> chatInputSetPosition;
		Function<void, String> chatInputSetText;

		// Game
		Function<void> clearMultiplayerMessages;
		Function<void, Bool> enableEvent_Render;
		Function<void, Bool> enableEvent_RenderFocus;
		Function<void, Bool> enable_DamageAnims;
		Function<void, Bool> enable_NicknameId;
		Function<void, Bool> enable_WeaponTrail;
		Function<void> exitGame;
		Function<Float> getDayLength;
		Function<Int> getFpsRate;
		Function<Float> getLODStrengthModifier;
		Function<Float> getLODStrengthOverride;
		Function<NetworkStats> getNetworkStats;
		Function<Float> getSightFactor;
		Function<GameTime> getTime;
		Function<Int, SQUserPointer> getVobType;
		Function<Bool, String> playVideo;
		Function<void, Int> setBloodMode;
		Function<void, Float> setDayLength;
		Function<void, Float> setLODStrengthModifier;
		Function<void, Float> setLODStrengthOverride;
		Function<void, Float> setSightFactor;
		Function<void, Int, Int, Int> setTime;
		Function<void, Bool> showPlayerStatus;
		Function<void, Int> switchInterpolation;

		// Hash
		Function<String, String> fileMd5;

		// Hero
		Function<Int> getExp;
		Function<Int> getFocusNpc;
		Function<Int> getGuildId;
		Function<String> getGuildName;
		Function<Int> getLearnPoints;
		Function<Int> getLevel;
		Function<Int> getNextLevelExp;
		Function<Int> getPingLimit;
		Function<Bool> isFrozen;
		Function<Bool> isInWater;
		Function<void, Int> setExp;
		Function<void, Bool> setFreeze;
		Function<void, Int> setGuild;
		Function<void, Int> setLearnPoints;
		Function<void, Int> setLevel;
		Function<void, Int> setNextLevelExp;
		Function<void, Int> setPingLimit;

		// Input
		Function<void, Bool> disableControls;
		Function<void, Int, Bool> disableKey;
		Function<void, Int, Bool> disableLogicalKey;
		[[deprecated]] Function<void, Bool> enableKeys;
		Function<Int> getKeyLayout;
		Function<String, Int> getKeyLetter;
		//Function< array<Int>? , Int> getLogicalKeyBinding;
		Function<Bool> isControlsDisabled;
		Function<Bool, Int> isKeyDisabled;
		Function<Bool, Int> isKeyPressed;
		Function<Bool, Int> isKeyToggled;
		[[deprecated]] Function<Bool> isKeysEnabled;
		Function<Bool, Int> isLogicalKeyDisabled;
		Function<Bool, Int> isLogicalKeyPressed;
		Function<Bool, Int> isMouseBtnPressed;
		Function<void, Int> resetLogicalKeys;
		Function<void> saveLogicalKeys;
		Function<void, String> setClipboardText;
		Function<void, Int> setKeyLayout;
		//Function<void, Int, array<Int>?> setLogicalKeyBinding;

		// Interface
		Function<Int, Int> anx;
		Function<Int, Int> any;
		//Function < {x, y, bpp} ... > getAvailableResolutions;
		Function<Position2d, Int> getBarPosition;
		Function<Size2d, Int> getBarSize;
		Function<Position2d> getCursorPosition;
		Function<Position2d> getCursorPositionPx;
		Function<Float> getCursorSensitivity;
		Function<Position2d> getCursorSize;
		Function<Position2d> getCursorSizePx;
		Function<String> getCursorTxt;
		Function<Int, Int> getHudMode;
		Function<Resolution> getResolution;
		Function<Bool> isConsoleOpen;
		Function<Bool> isCursorVisible;
		Function<Int> letterDistance;
		Function<Int> letterHeight;
		Function<Int> letterHeightPx;
		Function<Int, String> letterWidth;
		Function<Int, String> letterWidthPx;
		Function<Int, Int> nax;
		Function<Int, Int> nay;
		Function<void, Int, Int, Int> setBarPosition;
		Function<void, Int, Int> setBarSize;
		Function<void, Int, Int> setCursorPosition;
		Function<void, Int, Int> setCursorPositionPx;
		Function<void, Float> setCursorSensitivity;
		Function<void, Int, Int> setCursorSize;
		Function<void, Int, Int> setCursorSizePx;
		Function<void, String> setCursorTxt;
		Function<void, Bool> setCursorVisible;
		Function<void, Int, Int> setHudMode;
		Function<Bool, Int, Int, Int> setResolution;
		Function<String> textGetFont;
		Function<void, String> textSetFont;
		Function<Int, String> textWidth;
		Function<Int, String> textWidthPx;

		// Inventory
		Function<void> clearInventory;
		Function<void> closeInventory;
		Function<Int> getCurrentInventorySlot;
		//Function < {instance, amount, name}... > getEq;
		Function<Item, Int> getItemBySlot;
		Function<Int, Int> hasItem;
		Function<Bool> isInventoryOpen;
		Function<void> openInventory;

		// Item
		Function<String, String> getItemDescription;
		// getItemInfo deprecated
		Function<String, String> getItemName;
		Function<String, String> getItemValue;

		// Music
		Function<void, Bool> disableMusicSystem;
		Function<Float> getMusicVolume;
		Function<Float> getSoundVolume;
		Function<Bool> isMusicSystemDisabled;
		Function<void, Float> setMusicVolume;
		Function<void, Float> setSoundVolume;

		// NPC
		Function<Int, String> createNpc;
		Function<Bool, Int> destroyNpc;
		Function<Bool, Int, String> spawnNpc;
		Function<Bool, Int> unspawnNpc;

		// Player
		Function<Bool, Int, String> addEffect;
		Function<Bool, Int, Int> applyPlayerOverlay;
		Function<Bool, Int, Int, Int> attackPlayer;
		Function<Bool, Int, Int, Int> attackPlayerMagic;
		Function<Bool, Int, Int> attackPlayerRanged;
		Function<void, Int, Int, Int, Int, Bool, Int, String> attackPlayerWithEffect;
		Function<void, Int, Int> drawWeapon;
		[[deprecated]] Function<Bool, Int, Int> equipArmor;
		[[deprecated]] Function<Bool, Int, Int> equipHelmet;
		[[deprecated]] Function<Bool, Int, Int, Int> equipItem;
		[[deprecated]] Function<Bool, Int, Int> equipMeleeWeapon;
		[[deprecated]] Function<Bool, Int, Int> equipShield;
		Function<Int, Int> getActFrame;
		Function<String, Int> getFaceAniName;
		Function<Int, Int> getLastHitAniFrame;
		Function<Int, Int> getPlayerAmulet;
		Function<Float, Int> getPlayerAngle;
		Function<String, Int> getPlayerAni;
		Function<Int, Int> getPlayerAniId;
		Function<Int, Int, String> getPlayerAniIdByName;
		Function<String, Int, Int> getPlayerAniNameById;
		Function<Int, Int> getPlayerArmor;
		//Function<Vec3, Int> getPlayerAtVector;
		Function<Int, Int> getPlayerBelt;
		Function<Bool, Int> getPlayerCollision;
		Function<Color, Int > getPlayerColor;
		Function<Int, Int> getPlayerDexterity;
		Function<Float, Int> getPlayerFatness;
		Function<Int, Int> getPlayerHealth;
		Function<Int, Int> getPlayerHelmet;
		Function<Int, SQUserPointer> getPlayerIdByPtr;
		Function<String, Int> getPlayerInstance;
		Function<Int, Int> getPlayerMagicLevel;
		Function<Int, Int> getPlayerMana;
		//Function<Mat4, Int> getPlayerMatrix;
		Function<Int, Int> getPlayerMaxHealth;
		Function<Int, Int> getPlayerMaxMana;
		Function<Int, Int> getPlayerMeleeWeapon;
		Function<String, Int> getPlayerName;
		Function<Int, Int> getPlayerPing;
		Function<Position3d, Int > getPlayerPosition;
		Function<Int, Int, Int> getPlayerProtection;
		Function<SQUserPointer, Int> getPlayerPtr;
		Function<Int, Int> getPlayerRangedWeapon;
		Function<Int, Int> getPlayerReadiedWeapon;
		Function<Int, Int, Int> getPlayerRing;
		Function<Position3d, Int > getPlayerScale;
		Function<Int, Int> getPlayerShield;
		Function<Int, Int, Int> getPlayerSkillWeapon;
		Function<Int, Int, Int> getPlayerSpell;
		Function<Int, Int> getPlayerStrength;
		//Function<void, Int, Int, Bool> getPlayerTalent; // SUS
		Function<Int, Int> getPlayerType;
		Function<BodyVisual, Int> getPlayerVisual;
		Function<Float, Int> getPlayerVisualAlpha;
		Function<Int, Int> getPlayerWeaponMode;
		Function<void, Int, Int, Int> giveItem;
		Function<Bool, Int, Int> hitPlayer;
		Function<Bool, Int> isPlayerCreated;
		Function<Bool, Int> isPlayerDead;
		Function<Bool, Int> isPlayerInWater;
		Function<Bool, Int> isPlayerStreamed;
		Function<Bool, Int> isPlayerUnconscious;
		Function<void, Int, String> playAni;
		Function<void, Int, Int> playAniId;
		Function<void, Int> playGesticulation;
		Function<void, Int, Int, Int> readySpell;
		Function<Bool, Int, String> removeEffect;
		Function<void, Int, Int, Int> removeItem;
		Function<Bool, Int, Int> removePlayerOverlay;
		Function<void, Int> removeWeapon;
		Function<void, Int, Float> setPlayerAngle;
		Function<void, Int, Bool> setPlayerCollision;
		Function<void, Int, Int, Int, Int> setPlayerColor;
		Function<void, Int, Int> setPlayerDexterity;
		Function<void, Int, Float> setPlayerFatness;
		Function<void, Int, Int> setPlayerHealth;
		Function<void, Int, String> setPlayerInstance;
		Function<void, Int, Int> setPlayerMagicLevel;
		Function<void, Int, Int> setPlayerMana;
		Function<void, Int, Int> setPlayerMaxHealth;
		Function<void, Int, Int> setPlayerMaxMana;
		Function<void, Int, String> setPlayerName;
		Function<void, Int> setPlayerOnFloor;
		Function<void, Int, Float, Float, Float> setPlayerPosition;
		Function<void, Int, Float, Float, Float> setPlayerScale;
		Function<void, Int, Int, Int> setPlayerSkillWeapon;
		Function<void, Int, Int> setPlayerStrength;
		Function<void, Int, Int, Bool> setPlayerTalent;
		Function<void, Int, String, Int, String, Int> setPlayerVisual;
		Function<Bool, Int, Float> setPlayerVisualAlpha;
		Function<void, Int, Int> setPlayerWeaponMode;
		Function<Bool, Int, String> startFaceAni;
		Function<void, Int, String> stopAni;
		Function<void, Int, Int> stopAniId;
		Function<Bool, Int> stopFaceAni;
		[[deprecated]] Function<void, Int> unequipArmor;
		[[deprecated]] Function<void, Int> unequipHelmet;
		Function<Bool, Int, Int> unequipItem;
		[[deprecated]] Function<void, Int> unequipMeleeWeapon;
		[[deprecated]] Function<void, Int> unequipRangedWeapon;
		[[deprecated]] Function<void, Int> unequipShield;
		Function<void, Int> unreadySpell;
		Function<void, Int, String, Int> useClosestMob;
		Function<void, Int, Int, Int> useItem;

		// World
		Function<void, String, String> changeWorld;
		Function<String> getWorld;
	};
}
#endif // NONUT_G2O_CLIENT_FUNCTION_CLIENT_FUNCTIONS_H
