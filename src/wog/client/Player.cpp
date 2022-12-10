#include "Player.h"

#include "constant/ClientConstants.h"
#include "event/ClientEventHandlers.h"
#include "function/ClientFunctions.h"

using ClientEventHandlers = nonut::g2o::ClientEventHandlers;
using ClientConstants = nonut::g2o::ClientConstants;

namespace wog
{
	Player* Player::get()
	{
		if (instance == nullptr)
		{
			instance = new Player();
		}
		return instance;
	}

	Player::Player()
	{
		C_F->disableLogicalKey(ClientConstants::GAME_END, true);
	}
}
