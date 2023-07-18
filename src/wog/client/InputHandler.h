#ifndef WOG_CLIENT_INPUTHANDLER_H_
#define WOG_CLIENT_INPUTHANDLER_H_

#include "WogHeader.h"

namespace wog
{
	class InputHandler : public Singleton<InputHandler>
	{
	public:
		inline static HHOOK mouseHook{ nullptr };
		inline static HHOOK keyboardHook{ nullptr };

	private:
		InputHandler();

		friend Singleton;
	};
}

#endif // WOG_CLIENT_INPUTHANDLER_H_