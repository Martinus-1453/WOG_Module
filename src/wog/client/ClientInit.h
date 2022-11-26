#pragma once
#ifndef CLIENT_INIT_H
#define CLIENT_INIT_H
#include "pch.h"

#include "constant/ClientConstants.h"
#include "constant/SharedConstants.h"
#include "event/ClientEventHandlers.h"
#include "function/SharedFunctions.h"

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

		ClientEventHandlers::onPacketHandler.emplace_back([] (nonut::g2o::Packet& packet)
		{
			auto result = packet.readInt32();
			SHARED_FUNCTIONS->print(std::to_string(result));
		});

		ClientEventHandlers::onMouseClickHandler.emplace_back([](Int key)
			{
				nonut::g2o::Packet packet{};
				packet.writeInt32(key);
				String tekst = "twój stary";
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
#endif
