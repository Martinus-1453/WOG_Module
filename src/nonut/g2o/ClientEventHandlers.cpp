#include "pch.h"
#include "ClientEventHandlers.h"

#include "nonut/Function.h"

namespace nonut::g2o
{
	
	void onChangeResolution()
	{
		for (auto && function : onChangeResolutionHandler)
		{
			function();
		}
	}

	void onExit()
	{
		for (auto&& function : onExitHandler)
		{
			function();
		}
	}

	void onRender()
	{
		for (auto&& function : onRenderHandler)
		{
			function();
		}
	}

	void onRenderFocus(int type, int id, int x, int y, std::string name)
	{
		for (auto&& function : onRenderFocusHandler)
		{
			function(type, id, x, y, name);
		}
	}

	void onAnim(int id)
	{
		for (auto&& function : onAnimHandler)
		{
			function(id);
		}
	}

	void onDamage(int damage, int flags)
	{
		for (auto&& function : onDamageHandler)
		{
			function(damage, flags);
		}
	}

	void onEquip(std::string instance)
	{
		for (auto&& function : onEquipHandler)
		{
			function(instance);
		}
	}

	void onFocus(int currentId, int previousId)
	{
		for (auto&& function : onFocusHandler)
		{
			function(currentId, previousId);
		}
	}

	void onLostFocus(int type, int id, std::string name)
	{
		for (auto&& function : onLostFocusHandler)
		{
			function(type, id, name);
		}
	}

	void onPlayerUseItem(int id, int itemId, int from, int to)
	{
		for (auto&& function : onPlayerUseItemHandler)
		{
			function(id, itemId, from, to);
		}
	}

	void onRespawn()
	{
		for (auto&& function : onRespawnHandler)
		{
			function();
		}
	}

	void onShoot()
	{
		for (auto&& function : onShootHandler)
		{
			function();
		}
	}

	void onSink()
	{
		for (auto&& function : onSinkHandler)
		{
			function();
		}
	}

	void onSpellCast(int id)
	{
		for (auto&& function : onSpellCastHandler)
		{
			function(id);
		}
	}

	void onTakeFocus(int type, int id, std::string name)
	{
		for (auto&& function : onTakeFocusHandler)
		{
			function(type, id, name);
		}
	}

	void onTakeItem(std::string instance, int amount)
	{
		for (auto&& function : onTakeItemHandler)
		{
			function(instance, amount);
		}
	}

	void onUnequip(std::string instance)
	{
		for (auto&& function : onUnequipHandler)
		{
			function(instance);
		}
	}

	void onCommand(std::string command, std::string params)
	{
		for (auto&& function : onCommandHandler)
		{
			function(command, params);
		}
	}

	void onConsole(std::string command, std::string params)
	{
		for (auto&& function : onConsoleHandler)
		{
			function(command, params);
		}
	}

	void onKey(int key)
	{
		for (auto&& function : onKeyHandler)
		{
			function(key);
		}
	}

	void onPaste(std::string clipboard)
	{
		for (auto&& function : onPasteHandler)
		{
			function(clipboard);
		}
	}

	void onCloseInventory()
	{
		for (auto&& function : onCloseInventoryHandler)
		{
			function();
		}
	}

	void onInventorySlotChange(int from, int to)
	{
		for (auto&& function : onInventorySlotChangeHandler)
		{
			function(from, to);
		}
	}

	void onOpenInventory()
	{
		for (auto&& function : onOpenInventoryHandler)
		{
			function();
		}
	}

	void onMouseClick(int button)
	{
		for (auto&& function : onMouseClickHandler)
		{
			function(button);
		}
	}

	void onMouseMove(int x, int y)
	{
		for (auto&& function : onMouseMoveHandler)
		{
			function(x, y);
		}
	}

	void onMouseRelease(int button)
	{
		for (auto&& function : onMouseReleaseHandler)
		{
			function(button);
		}
	}

	void onMouseWheel(int z)
	{
		for (auto&& function : onMouseWheelHandler)
		{
			function(z);
		}
	}

	void onPlayerChangeColor(int id, int r, int g, int b)
	{
		for (auto&& function : onPlayerChangeColorHandler)
		{
			function(id, r, g, b);
		}
	}

	void onPlayerChangeNickname(int id, std::string nickname)
	{
		for (auto&& function : onPlayerChangeNicknameHandler)
		{
			function(id, nickname);
		}
	}

	void onPlayerChangePing(int id, int ping)
	{
		for (auto&& function : onPlayerChangePingHandler)
		{
			function(id, ping);
		}
	}

	void onPlayerChangeWeaponMode(int playerId, int oldWeaponMode, int newWeaponMode)
	{
		for (auto&& function : onPlayerChangeWeaponModeHandler)
		{
			function(playerId, oldWeaponMode, newWeaponMode);
		}
	}

	void onPlayerCreate(int id)
	{
		for (auto&& function : onPlayerCreateHandler)
		{
			function(id);
		}
	}

	void onPlayerDead(int id)
	{
		for (auto&& function : onPlayerCreateHandler)
		{
			function(id);
		}
	}

	void onPlayerDestroy(int id)
	{
		for (auto&& function : onPlayerDestroyHandler)
		{
			function(id);
		}
	}

	void onPlayerHit(int killerId, int playerId, int damage)
	{
		for (auto&& function : onPlayerHitHandler)
		{
			function(killerId, playerId, damage);
		}
	}

	void onPlayerMessage(int id, int r, int g, int b, std::string message)
	{
		for (auto&& function : onPlayerMessageHandler)
		{
			function(id, r, g, b, message);
		}
	}

	void onPlayerSpawn(int id)
	{
		for (auto&& function : onPlayerSpawnHandler)
		{
			function(id);
		}
	}

	void onPlayerTeleport(int id, std::string vobName)
	{
		for (auto&& function : onPlayerTeleportHandler)
		{
			function(id, vobName);
		}
	}

	void onPlayerUnspawn(int id)
	{
		for (auto&& function : onPlayerUnspawnHandler)
		{
			function(id);
		}
	}

	void onWorldChange(std::string world)
	{
		for (auto&& function : onWorldChangeHandler)
		{
			function(world);
		}
	}

	void onWorldEnter()
	{
		for (auto&& function : onWorldEnterHandler)
		{
			function();
		}
	}

	//TODO: MAKE IT BETTER AND NOT SQRAT DEPENDANT
#define BIND_EVENT_HANDLER(eventName) Sqrat::RootTable(vm).Func(#eventName "Cpp", &eventName); \
	Function<void, std::string, HSQOBJECT, int> eventName ## AddEventHandler("addEventHandler"); \
	Function<void> eventName ## TestHandler(#eventName "Cpp"); \
	eventName ## AddEventHandler(#eventName, eventName ## TestHandler.GetObject(), 1)

	void initializeClientEventHandlers()
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
