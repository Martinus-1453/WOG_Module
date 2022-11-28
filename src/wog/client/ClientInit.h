#ifndef WOG_CLIENT_CLIENT_INIT_H
#define WOG_CLIENT_CLIENT_INIT_H
#include "pch.h"

#include "constant/ClientConstants.h"
#include "constant/SharedConstants.h"
#include "event/ClientEventHandlers.h"
#include "function/SharedFunctions.h"
#include "StringHelpers.h"

using namespace SqModule;

using ClientConstants = nonut::g2o::ClientConstants;
using ClientEventHandlers = nonut::g2o::ClientEventHandlers;
using SharedConstants = nonut::g2o::SharedConstants;

namespace wog
{
	inline void clientInit()
	{
		ClientEventHandlers::init();
		ClientConstants::init();
		SharedConstants::init();

		ClientEventHandlers::onPacketHandler.emplace(
			nonut::ServerPacketType::HelloClient,
			[](nonut::g2o::Packet& packet)
			{
				auto result = packet.readString();
				SHARED_FUNCTIONS->print(result);
			});

		ClientEventHandlers::onMouseClickHandler.emplace_back([](Int key)
			{
				nonut::g2o::Packet packet{nonut::ClientPacketType::HelloServer};
				packet.writeInt32(key);
				String tekst = "Hello Server!";
				packet.writeString(tekst);
				packet.send(SharedConstants::RELIABLE_ORDERED);

				if (key == ClientConstants::MOUSE_LMB)
				{
					SHARED_FUNCTIONS->print("LMB");
					return;
				}

				if (key == ClientConstants::MOUSE_MMB)
				{
					SHARED_FUNCTIONS->print("MMB");
					return;
				}

				if (key == ClientConstants::MOUSE_RMB)
				{
					SHARED_FUNCTIONS->print("RMB");
					return;
				}
			});
	}
}
#endif // WOG_CLIENT_CLIENT_INIT_H
