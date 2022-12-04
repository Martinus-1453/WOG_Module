#include "ServerFunctions.h"

namespace nonut::g2o
{
	ServerFunctions::ServerFunctions():
		FUNCTION_CTOR(setPlayerHealth),
		FUNCTION_CTOR(setPlayerMaxHealth),
		FUNCTION_CTOR(setPlayerMana),
		FUNCTION_CTOR(setPlayerMaxMana)
	{
	}

	ServerFunctions* ServerFunctions::getInstance()
	{
		if(instance == nullptr)
		{
			instance = new ServerFunctions();
		}
		return instance;
	}
}
