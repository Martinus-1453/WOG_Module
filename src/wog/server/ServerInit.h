#pragma once
#ifndef SERVER_INIT_H
#define SERVER_INIT_H
#include "pch.h"

//#include "constant/ServerConstants.h"
#include "event/ServerEventHandlers.h"
#include "function/SharedFunctions.h"
#include "constant/SharedConstants.h"

using namespace SqModule;

//using ServerConstants = nonut::g2o::ServerConstants;
using ServerEventHandlers = nonut::g2o::ServerEventHandlers;

namespace wog
{
	inline void serverInit()
	{
		//ServerConstants::init();
		ServerEventHandlers::init();

		ServerEventHandlers::onPacketHandler.emplace_back([](Int playerId, nonut::g2o::Packet& packet)
		{
			SHARED_FUNCTIONS->print(std::to_string(packet.readInt32()));
			SHARED_FUNCTIONS->print(packet.readString());
		});

		ServerEventHandlers::onPlayerChangeWeaponModeHandler.emplace_back([](Int playerId, Int oldWeaponMode, Int newWeaponMode)
		{
				nonut::g2o::Packet packet{};
				packet.writeInt32(69);
				packet.send(playerId, nonut::g2o::SharedConstants::RELIABLE_ORDERED);
		});
		
	}
}
#endif
