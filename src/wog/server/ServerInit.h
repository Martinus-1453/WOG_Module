#ifndef WOG_SERVER_SERVER_INIT_H
#define WOG_SERVER_SERVER_INIT_H
#include "pch.h"

//#include "constant/ServerConstants.h"
#include "event/ServerEventHandlers.h"
#include "function/SharedFunctions.h"
#include "constant/SharedConstants.h"
#include "StringHelpers.h"

using namespace SqModule;

//using ServerConstants = nonut::g2o::ServerConstants;
using ServerEventHandlers = nonut::g2o::ServerEventHandlers;

namespace wog
{
	inline void serverInit()
	{
		//ServerConstants::init();
		ServerEventHandlers::init();

		ServerEventHandlers::onPacketHandler.emplace(
			nonut::ClientPacketType::HelloServer,
			[](Int playerId, nonut::g2o::Packet& packet)
			{
				SHARED_FUNCTIONS->print(std::to_string(packet.readInt32()));
				SHARED_FUNCTIONS->print(nonut::win1250ToUTF8(packet.readString()));
			});

		ServerEventHandlers::onPlayerChangeWeaponModeHandler.emplace_back(
			[](Int playerId, Int oldWeaponMode, Int newWeaponMode)
			{
				nonut::g2o::Packet packet{ nonut::ServerPacketType::HelloClient };
				String text = "Hello Client!";
				packet.writeString(text);
				packet.send(playerId, nonut::g2o::SharedConstants::RELIABLE_ORDERED);
			});
		
	}
}
#endif // WOG_SERVER_SERVER_INIT_H
