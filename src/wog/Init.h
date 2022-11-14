#pragma once
#include "pch.h"
#include "nonut/g2o/ClientEventHandlers.h"
#include "nonut/g2o/ClientFunctions.h"

using namespace SqModule;

namespace wog
{
	inline void Init()
	{
		nonut::g2o::initializeClientEventHandlers();

		nonut::g2o::onMouseClickHandler.emplace_back([](int key)
		{
			CLIENT_FUNCTIONS->print(std::to_string(key));
		});
	}
}
