#pragma once
#ifndef CLIENT_INIT_H
#define CLIENT_INIT_H
#include "pch.h"

#include "constant/ClientConstants.h"
#include "event/ClientEventHandlers.h"
#include "function/SharedFunctions.h"

using namespace SqModule;

using ClientConstants = nonut::g2o::ClientConstants;
using ClientEventHandlers = nonut::g2o::ClientEventHandlers;

namespace wog
{
	inline void clientInit()
	{
		nonut::g2o::ClientEventHandlers::init();
		nonut::g2o::ClientConstants::init();

		ClientEventHandlers::onMouseClickHandler.emplace_back([](Int key)
			{
				if (key == ClientConstants::MOUSE_LMB)
				{
					CLIENT_FUNCTIONS->setTime(12, 12, 0);
					const auto timeOfDay = CLIENT_FUNCTIONS->getTime();
					SHARED_FUNCTIONS->print(std::to_string(timeOfDay.day));
					SHARED_FUNCTIONS->print(std::to_string(timeOfDay.hour));
					SHARED_FUNCTIONS->print(std::to_string(timeOfDay.min));
					SHARED_FUNCTIONS->print("LMB");
					return;
				}

				if (key == ClientConstants::MOUSE_MMB)
				{
					const auto visual = CLIENT_FUNCTIONS->getPlayerVisual(ClientConstants::heroId);
					SHARED_FUNCTIONS->print(visual.bodyModel + ' ' + visual.headModel);
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
