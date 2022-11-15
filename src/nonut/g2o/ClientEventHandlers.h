#pragma once
#include <functional>
#include <string>
#include <vector>

namespace nonut::g2o
{
#define HANDLER_INIT(type, name) std::vector<std::function<type>> name ## Handler{}

	// General
	static void onChangeResolution();
	static void onExit();
	static void onRender();
	static void onRenderFocus(int type, int id, int x, int y, std::string name);
	// Hero
	static void onAnim(int id);
	static void onDamage(int damage, int flags);
	static void onEquip(std::string instance);
	static void onFocus(int currentId, int previousId);
	static void onLostFocus(int type, int id, std::string name);
	static void onPlayerUseItem(int id, int itemId, int from, int to);
	static void onRespawn();
	static void onShoot();
	static void onSink();
	static void onSpellCast(int id);
	static void onTakeFocus(int type, int id, std::string name);
	static void onTakeItem(std::string instance, int amount);
	static void onUnequip(std::string instance);
	// Input
	static void onCommand(std::string command, std::string params);
	static void onConsole(std::string command, std::string params);
	static void onKey(int key);
	static void onPaste(std::string clipboard);
	// Inventory
	static void onCloseInventory();
	static void onInventorySlotChange(int from, int to);
	void onOpenInventory();
	// Mouse
	static void onMouseClick(int button);
	static void onMouseMove(int x, int y);
	static void onMouseRelease(int button);
	static void onMouseWheel(int z);
	// Network
// TODO: Packet missing implementation
// void onPacket(Packet packet);
	// Mob
// TODO: needs work: userdata missing
//void onMobClose(userdata address, int type);
//void onMobInteract(userdata address, int type, int from, int to);
//void onMobOpen(userdata address, int type);

	// Player
	static void onPlayerChangeColor(int id, int r, int g, int b);
	static void onPlayerChangeNickname(int id, std::string nickname);
	static void onPlayerChangePing(int id, int ping);
	static void onPlayerChangeWeaponMode(int playerId, int oldWeaponMode, int newWeaponMode);
	static void onPlayerCreate(int id);
	static void onPlayerDead(int id);
	static void onPlayerDestroy(int id);
	static void onPlayerHit(int killerId, int playerId, int damage);
	static void onPlayerMessage(int id, int r, int g, int b, std::string message);
	static void onPlayerSpawn(int id);
	static void onPlayerTeleport(int id, std::string vobName);
	static void onPlayerUnspawn(int id);
	// World
	static void onWorldChange(std::string world);
	static void onWorldEnter();


	class ClientEventHandlers
	{
	public:
		// !!!INITIALIZATION!!!
		static void Init();

		static inline HANDLER_INIT(void(), onChangeResolution);
		static inline HANDLER_INIT(void(), onExit);
		static inline HANDLER_INIT(void(), onRender);
		static inline HANDLER_INIT(void(int, int, int, int, std::string), onRenderFocus);

		static inline HANDLER_INIT(void(int), onAnim);
		static inline HANDLER_INIT(void(int, int), onDamage);
		static inline HANDLER_INIT(void(std::string), onEquip);
		static inline HANDLER_INIT(void(int, int), onFocus);
		static inline HANDLER_INIT(void(int, int, std::string), onLostFocus);
		static inline HANDLER_INIT(void(int, int, int, int), onPlayerUseItem);
		static inline HANDLER_INIT(void(), onRespawn);
		static inline HANDLER_INIT(void(), onShoot);
		static inline HANDLER_INIT(void(), onSink);
		static inline HANDLER_INIT(void(int), onSpellCast);
		static inline HANDLER_INIT(void(int, int, std::string), onTakeFocus);
		static inline HANDLER_INIT(void(std::string, int), onTakeItem);
		static inline HANDLER_INIT(void(std::string), onUnequip);

		static inline HANDLER_INIT(void(std::string, std::string), onCommand);
		static inline HANDLER_INIT(void(std::string, std::string), onConsole);
		static inline HANDLER_INIT(void(int), onKey);
		static inline HANDLER_INIT(void(std::string), onPaste);
		static inline HANDLER_INIT(void(), onCloseInventory);
		static inline HANDLER_INIT(void(int, int), onInventorySlotChange);
		static inline HANDLER_INIT(void(), onOpenInventory);
		static inline HANDLER_INIT(void(int), onMouseClick);
		static inline HANDLER_INIT(void(int, int), onMouseMove);
		static inline HANDLER_INIT(void(int), onMouseRelease);
		static inline HANDLER_INIT(void(int), onMouseWheel);

		static inline HANDLER_INIT(void(int, int, int, int), onPlayerChangeColor);
		static inline HANDLER_INIT(void(int, std::string), onPlayerChangeNickname);
		static inline HANDLER_INIT(void(int, int), onPlayerChangePing);
		static inline HANDLER_INIT(void(int, int, int), onPlayerChangeWeaponMode);
		static inline HANDLER_INIT(void(int), onPlayerCreate);
		static inline HANDLER_INIT(void(int), onPlayerDead);
		static inline HANDLER_INIT(void(int), onPlayerDestroy);
		static inline HANDLER_INIT(void(int, int, int), onPlayerHit);
		static inline HANDLER_INIT(void(int, int, int, int, std::string), onPlayerMessage);
		static inline HANDLER_INIT(void(int), onPlayerSpawn);
		static inline HANDLER_INIT(void(int, std::string), onPlayerTeleport);
		static inline HANDLER_INIT(void(int), onPlayerUnspawn);

		static inline HANDLER_INIT(void(std::string), onWorldChange);
		static inline HANDLER_INIT(void(), onWorldEnter);
	};
}
