#ifndef WOG_CLIENT_CHAT_H
#define WOG_CLIENT_CHAT_H

#include <deque>
#include <vector>

#include "pch.h"
#include "class/Draw.h"

namespace wog
{
	enum ChatMode
	{
		IC,
		OOC,
		ANNOUNCEMENT,
		ADMIN,
	};

	class Chat
	{
	public:
		static Chat* get();
		ChatMode chatMode = ChatMode::IC;

	protected:
		Chat();

		std::vector<std::unique_ptr<nonut::g2o::Draw>> chatLine;
		std::vector<String> chatHistory;
		bool needsUpdate = false;

		static inline Chat* instance = nullptr;
	};
}
#endif // WOG_CLIENT_CHAT_H
