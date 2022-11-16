#pragma once
#ifndef CLIENT_INIT_H
#define CLIENT_INIT_H
#include "pch.h"

#include "nonut/g2o/client/constant/ClientConstants.h"
#include "nonut/g2o/client/event/ClientEventHandlers.h"

using namespace SqModule;

using ClientConstants = nonut::g2o::ClientConstants;
using ClientEventHandlers = nonut::g2o::ClientEventHandlers;

namespace wog
{
	inline void init()
	{
		nonut::g2o::ClientEventHandlers::init();
		nonut::g2o::ClientConstants::init();

		ClientEventHandlers::onMouseClickHandler.emplace_back([](int key)
			{
				if (key == ClientConstants::MOUSE_LMB)
				{
					CLIENT_FUNCTIONS->setTime(12, 12, 0);
					const auto timeOfDay = CLIENT_FUNCTIONS->getTime();
					CLIENT_FUNCTIONS->print(std::to_string(timeOfDay.day));
					CLIENT_FUNCTIONS->print(std::to_string(timeOfDay.hour));
					CLIENT_FUNCTIONS->print(std::to_string(timeOfDay.min));
					CLIENT_FUNCTIONS->print("LMB");
					return;
				}

				if (key == ClientConstants::MOUSE_MMB)
				{
					const auto visual = CLIENT_FUNCTIONS->getPlayerVisual(ClientConstants::heroId);
					CLIENT_FUNCTIONS->print(visual.bodyModel + ' ' + visual.headModel);
					CLIENT_FUNCTIONS->print("MMB");
					return;
				}

				if (key == ClientConstants::MOUSE_RMB)
				{
					CLIENT_FUNCTIONS->print("RMB");
					return;
				}
			});
	}
}
#endif
