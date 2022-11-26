#include "pch.h"
#include "ServerEventHandlers.h"

#include <thread>
#include <chrono>

#include "Function.h"
#include "Bind.h"

using namespace SqModule;

namespace nonut::g2o
{
	void onPacket(Int playerId, SQObject object)
	{
		Packet packet(object);
		for (auto&& function : ServerEventHandlers::onPacketHandler)
		{
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
			//std::this_thread::sleep_for(std::chrono::seconds(10));
			Bind::registerFunction("chuj", &onPacketWrapper, sizeof(&onPacketWrapper));
			Function<void, String, SQObject, Int> onPacketAddEventHandler("addEventHandler");
			Function<void> onPacketTestHandler("chuj");
			onPacketAddEventHandler("onPacket", onPacketTestHandler.getObject(), 1);
			//BIND_EVENT_HANDLER(onPacket);
			BIND_EVENT_HANDLER(onPlayerChangeWeaponMode);

			isInitialized = true;
		}
	}
}
