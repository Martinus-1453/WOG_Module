#include "Player.h"

#include "constant/ClientConstants.h"
#include "event/ClientEventHandlers.h"
#include "function/ClientFunctions.h"
#include "WogHeader.h"

using ClientEventHandlers = g2o::ClientEventHandlers;
using ClientConstants = g2o::ClientConstants;

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

		ClientEventHandlers::onKeyHandler.emplace_back([](Int key)
		{
			if (key == ClientConstants::KEY_END)
			{
				C_F->exitGame();
			}
		});
	}
}
