#pragma once
#include "pch.h"
#include "nonut/g2o/ClientConstants.h"
#include "nonut/g2o/ClientEventHandlers.h"
#include "nonut/g2o/ClientFunctions.h"

using namespace SqModule;

typedef nonut::g2o::ClientConstants ClientConstants;
typedef nonut::g2o::ClientEventHandlers ClientEventHandlers;

namespace wog
{
	inline void init()
	{
		nonut::g2o::ClientEventHandlers::Init();
		nonut::g2o::ClientConstants::Init();

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
