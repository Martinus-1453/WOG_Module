#include "ServerFunctions.h"

namespace nonut::g2o
{
	ServerFunctions::ServerFunctions():
		FUNCTION_CTOR(setPlayerHealth),
		FUNCTION_CTOR(setPlayerMaxHealth),
		FUNCTION_CTOR(setPlayerMana),
		FUNCTION_CTOR(setPlayerMaxMana),
		FUNCTION_CTOR(sendPlayerMessageToAll)
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
