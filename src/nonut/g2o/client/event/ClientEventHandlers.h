#ifndef NONUT_G2O_CLIENT_EVENT_CLIENT_EVENT_HANDLERS_H
#define NONUT_G2O_CLIENT_EVENT_CLIENT_EVENT_HANDLERS_H

#include <functional>
#include <string>
#include <vector>
#include "class/Packet.h"

namespace nonut::g2o
{
#define HANDLER_INIT(type, name) std::vector<std::function<type>> name ## Handler{}

	// General
	static void onChangeResolution();
	static void onExit();
	static void onRender();
	static void onRenderFocus(Int type, Int id, Int x, Int y, String name);
	// Hero
	static void onAnim(Int id);
	static void onDamage(Int damage, Int flags);
	static void onEquip(String instance);
	static void onFocus(Int currentId, Int previousId);
	static void onLostFocus(Int type, Int id, String name);
	static void onPlayerUseItem(Int id, Int itemId, Int from, Int to);
	static void onRespawn();
	static void onShoot();
	static void onSink();
	static void onSpellCast(Int id);
	static void onTakeFocus(Int type, Int id, String name);
	static void onTakeItem(String instance, Int amount);
	static void onUnequip(String instance);
	// Input
	static void onCommand(String command, String params);
	static void onConsole(String command, String params);
	static void onKey(Int key);
	static void onPaste(String clipboard);
	// Inventory
	static void onCloseInventory();
	static void onInventorySlotChange(Int from, Int to);
	void onOpenInventory();
	// Mouse
	static void onMouseClick(Int button);
	static void onMouseMove(Int x, Int y);
	static void onMouseRelease(Int button);
	static void onMouseWheel(Int z);
	// Network
	// TODO: Packet missing implementation
	static void onPacket(SQObject object);
	// Mob
	// TODO: needs work: userdata missing
	//void onMobClose(userdata address, Int type);
	//void onMobInteract(userdata address, Int type, Int from, Int to);
	//void onMobOpen(userdata address, Int type);

	// Player
	static void onPlayerChangeColor(Int id, Int r, Int g, Int b);
	static void onPlayerChangeNickname(Int id, String nickname);
	static void onPlayerChangePing(Int id, Int ping);
	static void onPlayerChangeWeaponMode(Int playerId, Int oldWeaponMode, Int newWeaponMode);
	static void onPlayerCreate(Int id);
	static void onPlayerDead(Int id);
	static void onPlayerDestroy(Int id);
	static void onPlayerHit(Int killerId, Int playerId, Int damage);
	static void onPlayerMessage(Int id, Int r, Int g, Int b, String message);
	static void onPlayerSpawn(Int id);
	static void onPlayerTeleport(Int id, String vobName);
	static void onPlayerUnspawn(Int id);
	// World
	static void onWorldChange(String world);
	static void onWorldEnter();


	class ClientEventHandlers
	{
	public:
		// !!!INITIALIZATION!!!
		static void init();

		static inline HANDLER_INIT(void(Packet&), onPacket);

		static inline HANDLER_INIT(void(), onChangeResolution);
		static inline HANDLER_INIT(void(), onExit);
		static inline HANDLER_INIT(void(), onRender);
		static inline HANDLER_INIT(void(Int, Int, Int, Int, String&), onRenderFocus);

		static inline HANDLER_INIT(void(Int), onAnim);
		static inline HANDLER_INIT(void(Int, Int), onDamage);
		static inline HANDLER_INIT(void(String&), onEquip);
		static inline HANDLER_INIT(void(Int, Int), onFocus);
		static inline HANDLER_INIT(void(Int, Int, String&), onLostFocus);
		static inline HANDLER_INIT(void(Int, Int, Int, Int), onPlayerUseItem);
		static inline HANDLER_INIT(void(), onRespawn);
		static inline HANDLER_INIT(void(), onShoot);
		static inline HANDLER_INIT(void(), onSink);
		static inline HANDLER_INIT(void(Int), onSpellCast);
		static inline HANDLER_INIT(void(Int, Int, String&), onTakeFocus);
		static inline HANDLER_INIT(void(String&, Int), onTakeItem);
		static inline HANDLER_INIT(void(String&), onUnequip);

		static inline HANDLER_INIT(void(String&, String&), onCommand);
		static inline HANDLER_INIT(void(String&, String&), onConsole);
		static inline HANDLER_INIT(void(Int), onKey);
		static inline HANDLER_INIT(void(String&), onPaste);
		static inline HANDLER_INIT(void(), onCloseInventory);
		static inline HANDLER_INIT(void(Int, Int), onInventorySlotChange);
		static inline HANDLER_INIT(void(), onOpenInventory);
		static inline HANDLER_INIT(void(Int), onMouseClick);
		static inline HANDLER_INIT(void(Int, Int), onMouseMove);
		static inline HANDLER_INIT(void(Int), onMouseRelease);
		static inline HANDLER_INIT(void(Int), onMouseWheel);

		static inline HANDLER_INIT(void(Int, Int, Int, Int), onPlayerChangeColor);
		static inline HANDLER_INIT(void(Int, String&), onPlayerChangeNickname);
		static inline HANDLER_INIT(void(Int, Int), onPlayerChangePing);
		static inline HANDLER_INIT(void(Int, Int, Int), onPlayerChangeWeaponMode);
		static inline HANDLER_INIT(void(Int), onPlayerCreate);
		static inline HANDLER_INIT(void(Int), onPlayerDead);
		static inline HANDLER_INIT(void(Int), onPlayerDestroy);
		static inline HANDLER_INIT(void(Int, Int, Int), onPlayerHit);
		static inline HANDLER_INIT(void(Int, Int, Int, Int, String&), onPlayerMessage);
		static inline HANDLER_INIT(void(Int), onPlayerSpawn);
		static inline HANDLER_INIT(void(Int, String&), onPlayerTeleport);
		static inline HANDLER_INIT(void(Int), onPlayerUnspawn);

		static inline HANDLER_INIT(void(String&), onWorldChange);
		static inline HANDLER_INIT(void(), onWorldEnter);
	};
}
#endif // NONUT_G2O_CLIENT_EVENT_CLIENT_EVENT_HANDLERS_H
