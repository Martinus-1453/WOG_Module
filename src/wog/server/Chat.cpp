#include "Chat.h"

#include "event/ServerEventHandlers.h"
#include "function/ServerFunctions.h"

namespace wog
{
	Chat* Chat::get()
	{
		if (instance == nullptr)
		{
			instance = new Chat();
		}
		return instance;
	}

	Chat::Chat()
	{
		nonut::g2o::ServerEventHandlers::onPlayerMessageHandler.emplace_back([this](Int playerId, String message)
			{
				S_F->sendPlayerMessageToAll(playerId, 255, 255, 255, message);
			});
	}
}
