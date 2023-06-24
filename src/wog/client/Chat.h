#ifndef WOG_CLIENT_CHAT_H
#define WOG_CLIENT_CHAT_H

#include <vector>

#include "CommonHeader.h"
#include "WogHeader.h"
#include "class/ui/Draw.h"

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

	class Chat : public Singleton<Chat>
	{
	public:
		ChatMode chatMode = Ic;

	protected:
		Chat();

		std::vector<std::vector<std::unique_ptr<g2o::Draw>>> chatLine;
		std::vector<ChatEntry> chatHistory;
		bool needsUpdate = false;

		Int letterWidth;
		Int letterHeight;

		float maxWidth = 0.75f;

		friend Singleton;
	};
}
#endif // WOG_CLIENT_CHAT_H
