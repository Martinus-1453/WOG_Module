#include "InputHandler.h"
#include "Hook.h"
#include "event/ClientEventHandlers.h"

namespace wog
{
	InputHandler::InputHandler()
	{
		//keyboardHook = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, hInstApp, GetCurrentThreadId());
		//mouseHook = SetWindowsHookEx(WH_MOUSE, MouseProc, hInstApp, GetCurrentThreadId());

		//g2o::ClientEventHandlers::onExitHandler.emplace_back([]
		//	{
		//		UnhookWindowsHookEx(keyboardHook);
		//		UnhookWindowsHookEx(mouseHook);
		//	});
	}
}
