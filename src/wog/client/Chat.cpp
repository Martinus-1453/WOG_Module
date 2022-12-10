#include "Chat.h"

#include "constant/ClientConstants.h"
#include "event/ClientEventHandlers.h"
#include "function/ClientFunctions.h"

using ClientEventHandlers = nonut::g2o::ClientEventHandlers;
using ClientConstants = nonut::g2o::ClientConstants;

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

	inline void openChat()
	{
		C_F->chatInputOpen();
		C_F->setFreeze(true);
		C_F->disableControls(true);
	}

	inline void closeChat()
	{
		C_F->chatInputClose();
		C_F->setFreeze(false);
		C_F->disableControls(false);
	}

	Chat::Chat()
	{
		// POLISH CHARACTERS ARE SET HERE
		C_F->setKeyLayout(ClientConstants::KEY_LAYOUT_PL);

		for (int i = 0; i < 10; ++i)
		{
			chatLine.emplace_back(std::make_unique<nonut::g2o::Draw>(0, 0, " "));
			const auto line = chatLine.back().get();
			line->setPosition(C_F->anx(5), line->height * i * 1.15f);
			line->visible = true;
			C_F->chatInputSetPosition(0, line->height * (i + 1) * 1.15f);
		}

		ClientEventHandlers::onKeyHandler.emplace_back([this](Int key)
			{
				if (key == ClientConstants::KEY_T)
				{
					if (!C_F->chatInputIsOpen())
					{
						// OPEN CHAT HERE
						openChat();
					}
					return;
				}

				if (key == ClientConstants::KEY_ESCAPE)
				{
					if (C_F->chatInputIsOpen())
					{
						// CLOSE CHAT HERE
						closeChat();
						return;
					}
				}

				if (key == ClientConstants::KEY_DELETE)
				{
					if (C_F->chatInputIsOpen())
					{
						C_F->chatInputClear();
					}
					return;
				}

				if (key == ClientConstants::KEY_RETURN)
				{
					if (C_F->chatInputIsOpen())
					{
						if (!C_F->chatInputGetText().empty())
						{
							// CLOSE CHAT HERE
							C_F->chatInputSend();
							C_F->chatInputClear();
							closeChat();
						}
						else
						{
							closeChat();
						}
					}
				}
			});

		ClientEventHandlers::onPlayerMessageHandler.emplace_back([this](Int id, Int r, Int g, Int b, String message)
			{
				chatHistory.emplace_back(message);
				needsUpdate = true;

			});

		ClientEventHandlers::onRenderHandler.emplace_back([this](Float deltaTime)
			{
				if (needsUpdate)
				{
					for (int i = chatLine.size() - 1, j = chatHistory.size() - 1;
						i >= 0 && j >= 0; --i, --j)
					{

						chatLine[i]->text = chatHistory[j];
					}
					needsUpdate = false;
				}
			});
	}
}
