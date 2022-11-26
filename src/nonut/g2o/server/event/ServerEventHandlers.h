#pragma once
#ifndef SERVER_EVENT_HANDLERS_H
#define SERVER_EVENT_HANDLERS_H

#include <functional>
#include <string>
#include <vector>
#include "class/Packet.h"

namespace nonut::g2o
{
#define HANDLER_INIT(type, name) std::vector<std::function<type>> name ## Handler{}

	
	// Network
	static void onPacket(Int playerId, SQObject object);

	static void onPlayerChangeWeaponMode(Int playerId, Int oldWeaponMode, Int newWeaponMode);

	class ServerEventHandlers
	{
	public:
		// !!!INITIALIZATION!!!
		static void init();

		static inline HANDLER_INIT(void(Int ,Packet&), onPacket);
		static inline HANDLER_INIT(void(Int, Int, Int), onPlayerChangeWeaponMode);
	};
}
#endif
