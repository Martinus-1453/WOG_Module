#include "Chat.h"

#include <regex>
#include <utility>

#include "constant/ClientConstants.h"
#include "event/ClientEventHandlers.h"
#include "function/ClientFunctions.h"

using ClientEventHandlers = nonut::g2o::ClientEventHandlers;
using ClientConstants = nonut::g2o::ClientConstants;
using Draw = nonut::g2o::Draw;

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

		nonut::g2o::Draw sampleDraw(0, 0, "c");
		letterHeight = sampleDraw.height;
		letterWidth = sampleDraw.width;

		for (int i = 0; i < 10; ++i)
		{
			chatLine.emplace_back();
			C_F->chatInputSetPosition(0, letterHeight * (i + 1) * 1.15f);
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
				std::vector<HighlightRange> matches;
				auto start = 0;
				auto end = 0;
				Highlight highlight = Normal;

				for(int i = 0; i < message.size(); ++i)
				{
					if(message[i] == '#')
					{
						for (int j = i + 1; j < message.size(); ++j)
						{
							if(message[j] == '#')
							{
								matches.emplace_back(Me, i, j);
								i = j;
								break;
							}
						}
					}
					else if(message[i] == '<')
					{
						for (int j = i + 1; j < message.size(); ++j)
						{
							if (message[j] == '>')
							{
								matches.emplace_back(Do, i, j);
								i = j;
								break;
							}
						}
					}
					else
					{
						if(matches.empty())
						{
							matches.emplace_back(Normal, i, i);
						}
						else if(matches.back().highlightType == Normal)
						{
							matches.back().end = i;
						}
						else
						{
							matches.emplace_back(Normal, i, i);
						}
					}
				}

				needsUpdate = true;
				chatHistory.emplace_back(id, std::move(message), std::move(matches));
			});

		ClientEventHandlers::onRenderHandler.emplace_back([this](Float deltaTime)
			{
				if (needsUpdate)
				{
					for (int i = chatLine.size() - 1, j = chatHistory.size() - 1;
						i >= 0 && j >= 0; --i, --j)
					{
						auto&& entry = chatHistory[j];
						auto&& line = chatLine[i];
						line.clear();
						line.emplace_back(std::make_unique<Draw>(C_F->anx(10), letterHeight * i * 1.15f, C_F->getPlayerName(entry.id) + ": "));
						line.back()->visible = true;
						for (int k = 0; k < entry.ranges.size(); ++k)
						{
							auto&& lastLine = line.back();
							auto pos = lastLine->getPosition();
							auto& [highlightType, start, end] = entry.ranges[k];
							line.emplace_back(std::make_unique<Draw>(
								pos.x + lastLine->width,
								pos.y,
								entry.text.substr(start, end - start + 1)));

							switch (highlightType)
							{
							case Normal:
								break;
							case Me:
								line.back()->setColor(0, 255, 0);
								break;
							case Do:
								line.back()->setColor(255, 255, 0);
								break;
							}

							line.back()->visible = true;
						}
						
						
						/*chatLine[i]->text = C_F->getPlayerName(chatHistory[j].id) + ": " + chatHistory[j].text;*/
					}
					needsUpdate = false;
				}
			});
	}
}
