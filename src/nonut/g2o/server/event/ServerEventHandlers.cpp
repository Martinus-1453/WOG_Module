#include "pch.h"
#include "ServerEventHandlers.h"

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

	void ServerEventHandlers::init()
	{
		static bool isInitialized = false;

		// Prevent calling bind more than once
		if (!isInitialized)
		{
			// Binding for onPacket
			Bind::registerFunction("pckwrappserv", &onPacketWrapper, sizeof(&onPacketWrapper));
			Function<void, String, SQObject, Int> onPacketAddEventHandler("addEventHandler");
			Function<void> onPacketTestHandler("pckwrappserv");
			onPacketAddEventHandler("onPacket", onPacketTestHandler.getObject(), 1);

			BIND_EVENT_HANDLER(onPlayerChangeWeaponMode);
			BIND_EVENT_HANDLER(onPlayerMessage);

			isInitialized = true;
		}
	}
}
