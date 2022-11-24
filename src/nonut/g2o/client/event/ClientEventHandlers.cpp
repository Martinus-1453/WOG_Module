#include "pch.h"
#include "ClientEventHandlers.h"
#include "Function.h"

using namespace SqModule;

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

	void onRenderFocus(Int type, Int id, Int x, Int y, String name)
	{
		for (auto&& function : ClientEventHandlers::onRenderFocusHandler)
		{
			function(type, id, x, y, name);
		}
	}

	void onAnim(Int id)
	{
		for (auto&& function : ClientEventHandlers::onAnimHandler)
		{
			function(id);
		}
	}

	void onDamage(Int damage, Int flags)
	{
		for (auto&& function : ClientEventHandlers::onDamageHandler)
		{
			function(damage, flags);
		}
	}

	void onEquip(String instance)
	{
		for (auto&& function : ClientEventHandlers::onEquipHandler)
		{
			function(instance);
		}
	}

	void onFocus(Int currentId, Int previousId)
	{
		for (auto&& function : ClientEventHandlers::onFocusHandler)
		{
			function(currentId, previousId);
		}
	}

	void onLostFocus(Int type, Int id, String name)
	{
		for (auto&& function : ClientEventHandlers::onLostFocusHandler)
		{
			function(type, id, name);
		}
	}

	void onPlayerUseItem(Int id, Int itemId, Int from, Int to)
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

	void onSpellCast(Int id)
	{
		for (auto&& function : ClientEventHandlers::onSpellCastHandler)
		{
			function(id);
		}
	}

	void onTakeFocus(Int type, Int id, String name)
	{
		for (auto&& function : ClientEventHandlers::onTakeFocusHandler)
		{
			function(type, id, name);
		}
	}

	void onTakeItem(String instance, Int amount)
	{
		for (auto&& function : ClientEventHandlers::onTakeItemHandler)
		{
			function(instance, amount);
		}
	}

	void onUnequip(String instance)
	{
		for (auto&& function : ClientEventHandlers::onUnequipHandler)
		{
			function(instance);
		}
	}

	void onCommand(String command, String params)
	{
		for (auto&& function : ClientEventHandlers::onCommandHandler)
		{
			function(command, params);
		}
	}

	void onConsole(String command, String params)
	{
		for (auto&& function : ClientEventHandlers::onConsoleHandler)
		{
			function(command, params);
		}
	}

	void onKey(Int key)
	{
		for (auto&& function : ClientEventHandlers::onKeyHandler)
		{
			function(key);
		}
	}

	void onPaste(String clipboard)
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

	void onInventorySlotChange(Int from, Int to)
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

	void onMouseClick(Int button)
	{
		for (auto&& function : ClientEventHandlers::onMouseClickHandler)
		{
			function(button);
		}
	}

	void onMouseMove(Int x, Int y)
	{
		for (auto&& function : ClientEventHandlers::onMouseMoveHandler)
		{
			function(x, y);
		}
	}

	void onMouseRelease(Int button)
	{
		for (auto&& function : ClientEventHandlers::onMouseReleaseHandler)
		{
			function(button);
		}
	}

	void onMouseWheel(Int z)
	{
		for (auto&& function : ClientEventHandlers::onMouseWheelHandler)
		{
			function(z);
		}
	}

	void onPlayerChangeColor(Int id, Int r, Int g, Int b)
	{
		for (auto&& function : ClientEventHandlers::onPlayerChangeColorHandler)
		{
			function(id, r, g, b);
		}
	}

	void onPlayerChangeNickname(Int id, String nickname)
	{
		for (auto&& function : ClientEventHandlers::onPlayerChangeNicknameHandler)
		{
			function(id, nickname);
		}
	}

	void onPlayerChangePing(Int id, Int ping)
	{
		for (auto&& function : ClientEventHandlers::onPlayerChangePingHandler)
		{
			function(id, ping);
		}
	}

	void onPlayerChangeWeaponMode(Int playerId, Int oldWeaponMode, Int newWeaponMode)
	{
		for (auto&& function : ClientEventHandlers::onPlayerChangeWeaponModeHandler)
		{
			function(playerId, oldWeaponMode, newWeaponMode);
		}
	}

	void onPlayerCreate(Int id)
	{
		for (auto&& function : ClientEventHandlers::onPlayerCreateHandler)
		{
			function(id);
		}
	}

	void onPlayerDead(Int id)
	{
		for (auto&& function : ClientEventHandlers::onPlayerCreateHandler)
		{
			function(id);
		}
	}

	void onPlayerDestroy(Int id)
	{
		for (auto&& function : ClientEventHandlers::onPlayerDestroyHandler)
		{
			function(id);
		}
	}

	void onPlayerHit(Int killerId, Int playerId, Int damage)
	{
		for (auto&& function : ClientEventHandlers::onPlayerHitHandler)
		{
			function(killerId, playerId, damage);
		}
	}

	void onPlayerMessage(Int id, Int r, Int g, Int b, String message)
	{
		for (auto&& function : ClientEventHandlers::onPlayerMessageHandler)
		{
			function(id, r, g, b, message);
		}
	}

	void onPlayerSpawn(Int id)
	{
		for (auto&& function : ClientEventHandlers::onPlayerSpawnHandler)
		{
			function(id);
		}
	}

	void onPlayerTeleport(Int id, String vobName)
	{
		for (auto&& function : ClientEventHandlers::onPlayerTeleportHandler)
		{
			function(id, vobName);
		}
	}

	void onPlayerUnspawn(Int id)
	{
		for (auto&& function : ClientEventHandlers::onPlayerUnspawnHandler)
		{
			function(id);
		}
	}

	void onWorldChange(String world)
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
	Function<void, String, SQObject, Int> eventName ## AddEventHandler("addEventHandler"); \
	Function<void> eventName ## TestHandler(#eventName "Cpp"); \
	eventName ## AddEventHandler(#eventName, eventName ## TestHandler.getObject(), 1)

	void ClientEventHandlers::init()
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
