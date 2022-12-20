#ifndef WOG_SERVER_SERVER_INIT_H
#define WOG_SERVER_SERVER_INIT_H
#include "pch.h"

//#include "constant/ServerConstants.h"
#include "Chat.h"
#include "Login.h"
#include "event/ServerEventHandlers.h"
#include "function/SharedFunctions.h"
#include "constant/SharedConstants.h"
#include "StringHelpers.h"
#include "function/ServerFunctions.h"

using namespace SqModule;

//using ServerConstants = nonut::g2o::ServerConstants;
using ServerEventHandlers = nonut::g2o::ServerEventHandlers;

namespace wog
{
	inline void serverInit()
	{
		//ServerConstants::init();
		ServerEventHandlers::init();
		std::ignore = Chat::get();
		std::ignore = Login::get();

		ServerEventHandlers::onPacketHandler.emplace(
			nonut::ClientPacketType::HelloServer,
			[](Int playerId, nonut::g2o::Packet& packet)
			{
				SH_F->print(std::to_string(packet.readInt32()));
				SH_F->print(nonut::win1250ToUTF8(packet.readString()));
				auto val = packet.readInt32();
				
				S_F->setPlayerHealth(playerId, val);
				S_F->setPlayerMana(playerId, val);
			});

		ServerEventHandlers::onPlayerChangeWeaponModeHandler.emplace_back(
			[](Int playerId, Int oldWeaponMode, Int newWeaponMode)
			{
				nonut::g2o::Packet packet{ nonut::ServerPacketType::HelloClient };
				String text = "Hello Client!";
				S_F->setPlayerMaxHealth(playerId, 100);
				S_F->setPlayerMaxMana(playerId, 100);
				packet.writeString(text);
				packet.send(playerId, nonut::g2o::SharedConstants::RELIABLE_ORDERED);
			});
		
	}
}
#endif // WOG_SERVER_SERVER_INIT_H
