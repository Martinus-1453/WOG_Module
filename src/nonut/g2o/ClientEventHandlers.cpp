#include "pch.h"
#include "ClientEventHandlers.h"

#include "nonut/Function.h"

namespace nonut::g2o
{
	void onChangeResolution()
	{
		for (auto&& function : ClientEventHandlers::onChangeResolutionHandler)
		{
			function();
		}
	}

	void onExit()
	{
		for (auto&& function : ClientEventHandlers::onExitHandler)
		{
			function();
		}
	}

	void onRender()
	{
		for (auto&& function : ClientEventHandlers::onRenderHandler)
		{
			function();
		}
	}

	void onRenderFocus(int type, int id, int x, int y, std::string name)
	{
		for (auto&& function : ClientEventHandlers::onRenderFocusHandler)
		{
			function(type, id, x, y, name);
		}
	}

	void onAnim(int id)
	{
		for (auto&& function : ClientEventHandlers::onAnimHandler)
		{
			function(id);
		}
	}

	void onDamage(int damage, int flags)
	{
		for (auto&& function : ClientEventHandlers::onDamageHandler)
		{
			function(damage, flags);
		}
	}

	void onEquip(std::string instance)
	{
		for (auto&& function : ClientEventHandlers::onEquipHandler)
		{
			function(instance);
		}
	}

	void onFocus(int currentId, int previousId)
	{
		for (auto&& function : ClientEventHandlers::onFocusHandler)
		{
			function(currentId, previousId);
		}
	}

	void onLostFocus(int type, int id, std::string name)
	{
		for (auto&& function : ClientEventHandlers::onLostFocusHandler)
		{
			function(type, id, name);
		}
	}

	void onPlayerUseItem(int id, int itemId, int from, int to)
	{
		for (auto&& function : ClientEventHandlers::onPlayerUseItemHandler)
		{
			function(id, itemId, from, to);
		}
	}

	void onRespawn()
	{
		for (auto&& function : ClientEventHandlers::onRespawnHandler)
		{
			function();
		}
	}

	void onShoot()
	{
		for (auto&& function : ClientEventHandlers::onShootHandler)
		{
			function();
		}
	}

	void onSink()
	{
		for (auto&& function : ClientEventHandlers::onSinkHandler)
		{
			function();
		}
	}

	void onSpellCast(int id)
	{
		for (auto&& function : ClientEventHandlers::onSpellCastHandler)
		{
			function(id);
		}
	}

	void onTakeFocus(int type, int id, std::string name)
	{
		for (auto&& function : ClientEventHandlers::onTakeFocusHandler)
		{
			function(type, id, name);
		}
	}

	void onTakeItem(std::string instance, int amount)
	{
		for (auto&& function : ClientEventHandlers::onTakeItemHandler)
		{
			function(instance, amount);
		}
	}

	void onUnequip(std::string instance)
	{
		for (auto&& function : ClientEventHandlers::onUnequipHandler)
		{
			function(instance);
		}
	}

	void onCommand(std::string command, std::string params)
	{
		for (auto&& function : ClientEventHandlers::onCommandHandler)
		{
			function(command, params);
		}
	}

	void onConsole(std::string command, std::string params)
	{
		for (auto&& function : ClientEventHandlers::onConsoleHandler)
		{
			function(command, params);
		}
	}

	void onKey(int key)
	{
		for (auto&& function : ClientEventHandlers::onKeyHandler)
		{
			function(key);
		}
	}

	void onPaste(std::string clipboard)
	{
		for (auto&& function : ClientEventHandlers::onPasteHandler)
		{
			function(clipboard);
		}
	}

	void onCloseInventory()
	{
		for (auto&& function : ClientEventHandlers::onCloseInventoryHandler)
		{
			function();
		}
	}

	void onInventorySlotChange(int from, int to)
	{
		for (auto&& function : ClientEventHandlers::onInventorySlotChangeHandler)
		{
			function(from, to);
		}
	}

	void onOpenInventory()
	{
		for (auto&& function : ClientEventHandlers::onOpenInventoryHandler)
		{
			function();
		}
	}

	void onMouseClick(int button)
	{
		for (auto&& function : ClientEventHandlers::onMouseClickHandler)
		{
			function(button);
		}
	}

	void onMouseMove(int x, int y)
	{
		for (auto&& function : ClientEventHandlers::onMouseMoveHandler)
		{
			function(x, y);
		}
	}

	void onMouseRelease(int button)
	{
		for (auto&& function : ClientEventHandlers::onMouseReleaseHandler)
		{
			function(button);
		}
	}

	void onMouseWheel(int z)
	{
		for (auto&& function : ClientEventHandlers::onMouseWheelHandler)
		{
			function(z);
		}
	}

	void onPlayerChangeColor(int id, int r, int g, int b)
	{
		for (auto&& function : ClientEventHandlers::onPlayerChangeColorHandler)
		{
			function(id, r, g, b);
		}
	}

	void onPlayerChangeNickname(int id, std::string nickname)
	{
		for (auto&& function : ClientEventHandlers::onPlayerChangeNicknameHandler)
		{
			function(id, nickname);
		}
	}

	void onPlayerChangePing(int id, int ping)
	{
		for (auto&& function : ClientEventHandlers::onPlayerChangePingHandler)
		{
			function(id, ping);
		}
	}

	void onPlayerChangeWeaponMode(int playerId, int oldWeaponMode, int newWeaponMode)
	{
		for (auto&& function : ClientEventHandlers::onPlayerChangeWeaponModeHandler)
		{
			function(playerId, oldWeaponMode, newWeaponMode);
		}
	}

	void onPlayerCreate(int id)
	{
		for (auto&& function : ClientEventHandlers::onPlayerCreateHandler)
		{
			function(id);
		}
	}

	void onPlayerDead(int id)
	{
		for (auto&& function : ClientEventHandlers::onPlayerCreateHandler)
		{
			function(id);
		}
	}

	void onPlayerDestroy(int id)
	{
		for (auto&& function : ClientEventHandlers::onPlayerDestroyHandler)
		{
			function(id);
		}
	}

	void onPlayerHit(int killerId, int playerId, int damage)
	{
		for (auto&& function : ClientEventHandlers::onPlayerHitHandler)
		{
			function(killerId, playerId, damage);
		}
	}

	void onPlayerMessage(int id, int r, int g, int b, std::string message)
	{
		for (auto&& function : ClientEventHandlers::onPlayerMessageHandler)
		{
			function(id, r, g, b, message);
		}
	}

	void onPlayerSpawn(int id)
	{
		for (auto&& function : ClientEventHandlers::onPlayerSpawnHandler)
		{
			function(id);
		}
	}

	void onPlayerTeleport(int id, std::string vobName)
	{
		for (auto&& function : ClientEventHandlers::onPlayerTeleportHandler)
		{
			function(id, vobName);
		}
	}

	void onPlayerUnspawn(int id)
	{
		for (auto&& function : ClientEventHandlers::onPlayerUnspawnHandler)
		{
			function(id);
		}
	}

	void onWorldChange(std::string world)
	{
		for (auto&& function : ClientEventHandlers::onWorldChangeHandler)
		{
			function(world);
		}
	}

	void onWorldEnter()
	{
		for (auto&& function : ClientEventHandlers::onWorldEnterHandler)
		{
			function();
		}
	}

	//TODO: MAKE IT BETTER AND NOT SQRAT DEPENDANT
#define BIND_EVENT_HANDLER(eventName) Sqrat::RootTable(vm).Func(#eventName "Cpp", &eventName); \
	Function<void, std::string, HSQOBJECT, int> eventName ## AddEventHandler("addEventHandler"); \
	Function<void> eventName ## TestHandler(#eventName "Cpp"); \
	eventName ## AddEventHandler(#eventName, eventName ## TestHandler.GetObject(), 1)

	void ClientEventHandlers::Init()
	{
		static bool isInitialized = false;

		// Prevent calling bind more than once
		if (!isInitialized)
		{
			BIND_EVENT_HANDLER(onChangeResolution);
			BIND_EVENT_HANDLER(onExit);
			BIND_EVENT_HANDLER(onRender);
			BIND_EVENT_HANDLER(onRenderFocus);
			BIND_EVENT_HANDLER(onAnim);
			BIND_EVENT_HANDLER(onDamage);
			BIND_EVENT_HANDLER(onEquip);
			BIND_EVENT_HANDLER(onFocus);
			BIND_EVENT_HANDLER(onLostFocus);
			BIND_EVENT_HANDLER(onPlayerUseItem);
			BIND_EVENT_HANDLER(onRespawn);
			BIND_EVENT_HANDLER(onShoot);
			BIND_EVENT_HANDLER(onSink);
			BIND_EVENT_HANDLER(onSpellCast);
			BIND_EVENT_HANDLER(onTakeFocus);
			BIND_EVENT_HANDLER(onTakeItem);
			BIND_EVENT_HANDLER(onUnequip);
			BIND_EVENT_HANDLER(onCommand);
			BIND_EVENT_HANDLER(onConsole);
			BIND_EVENT_HANDLER(onKey);
			BIND_EVENT_HANDLER(onPaste);
			BIND_EVENT_HANDLER(onCloseInventory);
			BIND_EVENT_HANDLER(onInventorySlotChange);
			BIND_EVENT_HANDLER(onOpenInventory);
			BIND_EVENT_HANDLER(onMouseClick);
			BIND_EVENT_HANDLER(onMouseMove);
			BIND_EVENT_HANDLER(onMouseRelease);
			BIND_EVENT_HANDLER(onMouseWheel);
			BIND_EVENT_HANDLER(onPlayerChangeColor);
			BIND_EVENT_HANDLER(onPlayerChangeNickname);
			BIND_EVENT_HANDLER(onPlayerChangePing);
			BIND_EVENT_HANDLER(onPlayerChangeWeaponMode);
			BIND_EVENT_HANDLER(onPlayerCreate);
			BIND_EVENT_HANDLER(onPlayerDead);
			BIND_EVENT_HANDLER(onPlayerDestroy);
			BIND_EVENT_HANDLER(onPlayerHit);
			BIND_EVENT_HANDLER(onPlayerMessage);
			BIND_EVENT_HANDLER(onPlayerSpawn);
			BIND_EVENT_HANDLER(onPlayerTeleport);
			BIND_EVENT_HANDLER(onPlayerUnspawn);
			BIND_EVENT_HANDLER(onWorldChange);
			BIND_EVENT_HANDLER(onWorldEnter);

			isInitialized = true;
		}
	}
}
