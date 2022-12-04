#ifndef WOG_CLIENT_CLIENT_INIT_H
#define WOG_CLIENT_CLIENT_INIT_H
#include "HUD.h"
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
		const auto hud = HUD::get();

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

				if (key == ClientConstants::MOUSE_LMB)
				{
					SHARED_FUNCTIONS->print("LMB");

					packet.writeInt32(
						CLIENT_FUNCTIONS->getPlayerHealth(ClientConstants::heroId) + 5);
				}
				else if (key == ClientConstants::MOUSE_MMB)
				{
					SHARED_FUNCTIONS->print("MMB");

					packet.writeInt32(
						CLIENT_FUNCTIONS->getPlayerHealth(ClientConstants::heroId) - 5);

				}
				else if (key == ClientConstants::MOUSE_RMB)
				{
					SHARED_FUNCTIONS->print("RMB");

					packet.writeInt32(
						CLIENT_FUNCTIONS->getPlayerMaxHealth(ClientConstants::heroId));
				}
				packet.send(SharedConstants::RELIABLE_ORDERED);
			});
	}
}
#endif // WOG_CLIENT_CLIENT_INIT_H
