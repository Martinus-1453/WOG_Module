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
		Ic,
		Ooc,
		Announcement,
		Admin,
		Info,
		Size
	};

	enum Highlight
	{
		Normal,
		Me,
		Do,
	};

	struct HighlightRange
	{
		Highlight highlightType;
		Int start;
		Int end;
	};

	struct ChatEntry
	{
		Int id;
		String text;
		std::vector<HighlightRange> ranges;
	};

	class Chat
	{
	public:
		static Chat* get();
		ChatMode chatMode = Ic;

	protected:
		Chat();

		std::vector<std::vector<std::unique_ptr<nonut::g2o::Draw>>> chatLine;
		std::vector<ChatEntry> chatHistory;
		bool needsUpdate = false;

		Int letterWidth;
		Int letterHeight;
		

		static inline Chat* instance = nullptr;
	};
}
#endif // WOG_CLIENT_CHAT_H
