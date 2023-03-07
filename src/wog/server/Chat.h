#ifndef WOG_SERVER_CHAT_H
#define WOG_SERVER_CHAT_H
#include "pch.h"

namespace wog
{
	class Chat
	{
	public:
		static Chat* get();

	protected:
		Chat();

		static inline Chat* instance = nullptr;
	};
}
#endif // WOG_SERVER_CHAT_H
