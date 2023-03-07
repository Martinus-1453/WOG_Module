#include "pch.h"
#include "ServerEventHandlers.h"

#include <ranges>

#include "Function.h"
#include "Bind.h"

using namespace SqModule;

namespace nonut::g2o
{
	void onPacket(Int playerId, SQObject object)
	{
		Packet packet(object);
		if (ServerEventHandlers::onPacketHandler.contains(packet.getType()))
		{
			const auto& function = ServerEventHandlers::onPacketHandler.at(packet.getType());
			function(playerId, packet);
		}
	}

	void onPlayerChangeWeaponMode(Int playerId, Int oldWeaponMode, Int newWeaponMode)
	{
		for (auto&& function : ServerEventHandlers::onPlayerChangeWeaponModeHandler)
		{
			function(playerId, oldWeaponMode, newWeaponMode);
		}
	}

	void onPlayerMessage(Int playerId, String message)
	{
		for (auto&& function : ServerEventHandlers::onPlayerMessageHandler)
		{
			function(playerId, message);
		}
	}

	void onPlayerCommand(Int playerId, String command, String params)
	{
		auto view = params
			| std::ranges::views::split(' ')
			| std::ranges::views::transform([](auto&& str)
			{
				return std::string_view(&*str.begin(), std::ranges::distance(str));
			});
		std::vector<String> paramView;

		for (auto&& item : view)
		{
			paramView.emplace_back(item);
		}

		for (auto&& function : ServerEventHandlers::onPlayerCommandHandler)
		{
			function(playerId, command, paramView);
		}
	}

	void onExit()
	{
		for (auto&& function : ServerEventHandlers::onExitHandler)
		{
			function();
		}
	}


	//TODO: MAKE IT BETTER AND NOT SQRAT DEPENDANT
#define BIND_EVENT_HANDLER(eventName) Sqrat::RootTable(vm).Func(#eventName "Wrapper", &eventName); \
	Function<void, String, SQObject, Int> eventName ## AddEventHandler("addEventHandler"); \
	Function<void> eventName ## TestHandler(#eventName "Wrapper"); \
	eventName ## AddEventHandler(#eventName, eventName ## TestHandler.getObject(), 1)

	SQInteger onPacketWrapper(HSQUIRRELVM v)
	{
		auto numArgs = sq_gettop(v); //number of arguments
		Int playerId{};
		SQObject packet{};
		sq_getinteger(v, -2, &playerId);
		sq_getstackobj(v, -1, &packet);

		onPacket(playerId, packet);

		return 0;
	}

	void ServerEventHandlers::bindOnPacket()
	{
		// Binding for onPacket
		Bind::registerFunction("pckwrappserv", &onPacketWrapper, sizeof(&onPacketWrapper));
		Function<void, String, SQObject, Int> onPacketAddEventHandler("addEventHandler");
		const Function<void> onPacketTestHandler("pckwrappserv");
		onPacketAddEventHandler("onPacket", onPacketTestHandler.getObject(), 1);
	}

	void ServerEventHandlers::init()
	{
		// Prevent calling bind more than once
		if (static bool isInitialized = false; !isInitialized)
		{
			bindOnPacket();

			BIND_EVENT_HANDLER(onPlayerChangeWeaponMode);
			BIND_EVENT_HANDLER(onPlayerMessage);
			BIND_EVENT_HANDLER(onPlayerCommand);
			BIND_EVENT_HANDLER(onExit);

			isInitialized = true;
		}
	}
}
