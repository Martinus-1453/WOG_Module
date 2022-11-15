#pragma once
#include "pch.h"
#include "nonut/g2o/ClientConstants.h"
#include "nonut/g2o/ClientEventHandlers.h"
#include "nonut/g2o/ClientFunctions.h"

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
					CLIENT_FUNCTIONS->print("LMB");
					return;
				}

				if (key == ClientConstants::MOUSE_MMB)
				{
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
