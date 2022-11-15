#pragma once
#include "pch.h"
#include "nonut/g2o/ClientConstants.h"
#include "nonut/g2o/ClientEventHandlers.h"
#include "nonut/g2o/ClientFunctions.h"

using namespace SqModule;

typedef nonut::g2o::ClientConstants ClientConstants;

namespace wog
{
	inline void Init()
	{
		nonut::g2o::initializeClientEventHandlers();
		nonut::g2o::ClientConstants::Init();

		nonut::g2o::onMouseClickHandler.emplace_back([](int key)
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
