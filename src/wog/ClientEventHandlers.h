#pragma once
#include <string>

namespace wog
{
	// General
	void onChangeResolution();
	void onExit();
	//void onInit(); // USELESS
	void onRender();
	void onRenderFocus(int type, int id, int x, int y, std::string name);

	// Hero
	void onAnim(int id);
	void onDamage(int damage, int flags);
	void onEquip(std::string instance);
	void onFocus(int currentId, int previousId);
	void onLostFocus(int type, int id, std::string name);
	void onPlayerUseItem(int id, int itemId, int from, int to);
	void onRespawn();
	void onShoot();
	void onSink();
	void onSpellCast(int id);
	void onTakeFocus(int type, int id, std::string name);
	void onTakeItem(std::string instance, int amount);
	void onUnequip(std::string instance);

	// Input
	void onCommand(std::string command, std::string params);
	void onConsole(std::string command, std::string params);
	void onKey(int key);
	void onPaste(std::string clipboard);

	// Inventory
	void onCloseInventory();
	void onInventoryySlotChange(int from, int to);
	void onOpenInventory();
	// Mob
	// TODO: needs work: userdata missing
	//void onMobClose(userdata address, int type);
	//void onMobInteract(userdata address, int type, int from, int to);
	//void onMobOpen(userdata address, int type);

	// Mouse
	void onMouseClick(int button);
	void onMouseMove(int x, int y);
	void onMouseRelease(int button);
	void onMouseWheel(int z);

	// Network
	// TODO: Packet missing implementation
	// void onPacket(Packet packet);

	// Player
	void onPlayerChangeColor(int id, int r, int g, int b);
	void onPlayerChangeNickname(int id, std::string nickname);
	void onPlayerChangePing(int id, int ping);
	void onPlayerChangeWeaponMode(int playerId, int oldWeaponMode, int newWeaponMode);
	void onPlayerCreate(int id);
	void onPlayerDead(int id);
	void onPlayerDestroy(int id);
	void onPlayerHit(int killerId, int playerId, int damage);
	void onPlayerMessage(int id, int r, int g, int b, std::string message);
	void onPlayerSpawn(int id);
	void onPlayerTeleport(int id, std::string vobName);
	void onPlayerUnspawn(int id);

	// World
	void onWorldChange(std::string world);
	void onWorldEnter();
}
