#pragma once
#include <functional>
#include <string>
#include <vector>

namespace nonut::g2o
{
#define HANDLER_INIT(type, name) std::vector<std::function<type>> name{}


	// !!!INITIALIZATION!!!
	void initializeClientEventHandlers();

	// General
	void onChangeResolution();
	inline HANDLER_INIT(void(), onChangeResolutionHandler);

	void onExit();
	inline HANDLER_INIT(void(), onExitHandler);

	//void onInit(); // USELESS

	void onRender();
	inline HANDLER_INIT(void(), onRenderHandler);

	void onRenderFocus(int type, int id, int x, int y, std::string name);
	inline HANDLER_INIT(void(int, int, int, int, std::string), onRenderFocusHandler);


	// Hero
	void onAnim(int id);
	inline HANDLER_INIT(void(int), onAnimHandler);

	void onDamage(int damage, int flags);
	inline HANDLER_INIT(void(int, int), onDamageHandler);

	void onEquip(std::string instance);
	inline HANDLER_INIT(void(std::string), onEquipHandler);

	void onFocus(int currentId, int previousId);
	inline HANDLER_INIT(void(int, int), onFocusHandler);

	void onLostFocus(int type, int id, std::string name);
	inline HANDLER_INIT(void(int, int, std::string), onLostFocusHandler);

	void onPlayerUseItem(int id, int itemId, int from, int to);
	inline HANDLER_INIT(void(int, int, int, int), onPlayerUseItemHandler);

	void onRespawn();
	inline HANDLER_INIT(void(), onRespawnHandler);

	void onShoot();
	inline HANDLER_INIT(void(), onShootHandler);

	void onSink();
	inline HANDLER_INIT(void(), onSinkHandler);

	void onSpellCast(int id);
	inline HANDLER_INIT(void(int), onSpellCastHandler);

	void onTakeFocus(int type, int id, std::string name);
	inline HANDLER_INIT(void(int, int, std::string), onTakeFocusHandler);

	void onTakeItem(std::string instance, int amount);
	inline HANDLER_INIT(void(std::string, int), onTakeItemHandler);

	void onUnequip(std::string instance);
	inline HANDLER_INIT(void(std::string), onUnequipHandler);


	// Input
	void onCommand(std::string command, std::string params);
	inline HANDLER_INIT(void(std::string, std::string), onCommandHandler);

	void onConsole(std::string command, std::string params);
	inline HANDLER_INIT(void(std::string, std::string), onConsoleHandler);

	void onKey(int key);
	inline HANDLER_INIT(void(int), onKeyHandler);

	void onPaste(std::string clipboard);
	inline HANDLER_INIT(void(std::string), onPasteHandler);


	// Inventory
	void onCloseInventory();
	inline HANDLER_INIT(void(), onCloseInventoryHandler);

	void onInventorySlotChange(int from, int to);
	inline HANDLER_INIT(void(int, int), onInventorySlotChangeHandler);

	void onOpenInventory();
	inline HANDLER_INIT(void(), onOpenInventoryHandler);


	// Mob
	// TODO: needs work: userdata missing
	//void onMobClose(userdata address, int type);
	//void onMobInteract(userdata address, int type, int from, int to);
	//void onMobOpen(userdata address, int type);


	// Mouse
	void onMouseClick(int button);
	inline HANDLER_INIT(void(int), onMouseClickHandler);

	void onMouseMove(int x, int y);
	inline HANDLER_INIT(void(int, int), onMouseMoveHandler);

	void onMouseRelease(int button);
	inline HANDLER_INIT(void(int), onMouseReleaseHandler);

	void onMouseWheel(int z);
	inline HANDLER_INIT(void(int), onMouseWheelHandler);


	// Network
	// TODO: Packet missing implementation
	// void onPacket(Packet packet);


	// Player
	void onPlayerChangeColor(int id, int r, int g, int b);
	inline HANDLER_INIT(void(int, int, int, int), onPlayerChangeColorHandler);

	void onPlayerChangeNickname(int id, std::string nickname);
	inline HANDLER_INIT(void(int, std::string), onPlayerChangeNicknameHandler);

	void onPlayerChangePing(int id, int ping);
	inline HANDLER_INIT(void(int, int), onPlayerChangePingHandler);

	void onPlayerChangeWeaponMode(int playerId, int oldWeaponMode, int newWeaponMode);
	inline HANDLER_INIT(void(int, int, int), onPlayerChangeWeaponModeHandler);

	void onPlayerCreate(int id);
	inline HANDLER_INIT(void(int), onPlayerCreateHandler);

	void onPlayerDead(int id);
	inline HANDLER_INIT(void(int), onPlayerDeadHandler);

	void onPlayerDestroy(int id);
	inline HANDLER_INIT(void(int), onPlayerDestroyHandler);

	void onPlayerHit(int killerId, int playerId, int damage);
	inline HANDLER_INIT(void(int, int, int), onPlayerHitHandler);

	void onPlayerMessage(int id, int r, int g, int b, std::string message);
	inline HANDLER_INIT(void(int, int, int, int, std::string), onPlayerMessageHandler);

	void onPlayerSpawn(int id);
	inline HANDLER_INIT(void(int), onPlayerSpawnHandler);

	void onPlayerTeleport(int id, std::string vobName);
	inline HANDLER_INIT(void(int, std::string), onPlayerTeleportHandler);

	void onPlayerUnspawn(int id);
	inline HANDLER_INIT(void(int), onPlayerUnspawnHandler);


	// World
	void onWorldChange(std::string world);
	inline HANDLER_INIT(void(std::string), onWorldChangeHandler);

	void onWorldEnter();
	inline HANDLER_INIT(void(), onWorldEnterHandler);
}
