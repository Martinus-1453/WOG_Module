#include "InputHandler.h"
#include "Hook.h"
#include "event/ClientEventHandlers.h"

namespace wog
{
	enum
	{
		MOUSE_DX = (MIN_MOUSE_BTNS_AND_CODES + 0),
		MOUSE_DY = (MIN_MOUSE_BTNS_AND_CODES + 1),
		MOUSE_UP = (MIN_MOUSE_BTNS_AND_CODES + 2),
		MOUSE_DOWN = (MIN_MOUSE_BTNS_AND_CODES + 3),
		MOUSE_LEFT = (MIN_MOUSE_BTNS_AND_CODES + 4),
		MOUSE_RIGHT = (MIN_MOUSE_BTNS_AND_CODES + 5),
		MOUSE_WHEELUP = (MIN_MOUSE_BTNS_AND_CODES + 6),
		MOUSE_WHEELDOWN = (MIN_MOUSE_BTNS_AND_CODES + 7),
		MOUSE_BUTTONLEFT = (MIN_MOUSE_BTNS_AND_CODES + 8),
		MOUSE_BUTTONRIGHT = (MIN_MOUSE_BTNS_AND_CODES + 9),
		MOUSE_BUTTONMID = (MIN_MOUSE_BTNS_AND_CODES + 10),
		MOUSE_XBUTTON1 = (MIN_MOUSE_BTNS_AND_CODES + 11),
		MOUSE_XBUTTON2 = (MIN_MOUSE_BTNS_AND_CODES + 12),
		MOUSE_XBUTTON3 = (MIN_MOUSE_BTNS_AND_CODES + 13),
		MOUSE_XBUTTON4 = (MIN_MOUSE_BTNS_AND_CODES + 14),
		MOUSE_XBUTTON5 = (MIN_MOUSE_BTNS_AND_CODES + 15),
	};

	LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
	{
		UINT16 repeatCount = lParam & 0xFFFF;
		UINT8 scanCode = (lParam & 0xFF << 16) >> 16;
		bool isExtendedKey = (lParam & 0x1 << 24) != 0;
		bool isAltKeyDown = (lParam & 0x1 << 29) != 0;
		bool wasKeyDown = (lParam & 0x1 << 30) != 0;
		const bool isKeyBeingReleased = (lParam & 0x1 << 31) != 0;

		if (nCode == HC_ACTION || nCode == HC_NOREMOVE)
		{
			if (!isKeyBeingReleased)
			{
				// KeyUp
			}
			else
			{
				// KeyDown
			}
		}

		return CallNextHookEx(InputHandler::keyboardHook, nCode, wParam, lParam);
	}

	LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
	{
		// TO DO: is this ok? MOUSEHOOKSTRUCTEX mouseData seems to be always set to 0
		const MOUSEHOOKSTRUCTEX* pMouseHookStruct = reinterpret_cast<MOUSEHOOKSTRUCTEX*>(lParam);
		if (nCode == HC_ACTION || nCode == HC_NOREMOVE)
		{
			//TODO: Invoke event here
			//switch (wParam)
			//{
			//case WM_LBUTTONDOWN:
			//	Sqrat::RootTable().GetFunction("callEvent").Evaluate<bool>("onKeyDown", MOUSE_BUTTONLEFT);
			//	break;

			//case WM_LBUTTONUP:
			//	Sqrat::RootTable().GetFunction("callEvent").Evaluate<bool>("onKeyUp", MOUSE_BUTTONLEFT);
			//	break;

			//case WM_RBUTTONDOWN:
			//	Sqrat::RootTable().GetFunction("callEvent").Evaluate<bool>("onKeyDown", MOUSE_BUTTONRIGHT);
			//	break;

			//case WM_RBUTTONUP:
			//	Sqrat::RootTable().GetFunction("callEvent").Evaluate<bool>("onKeyUp", MOUSE_BUTTONRIGHT);
			//	break;

			//case WM_MBUTTONDOWN:
			//	Sqrat::RootTable().GetFunction("callEvent").Evaluate<bool>("onKeyDown", MOUSE_BUTTONMID);
			//	break;

			//case WM_MBUTTONUP:
			//	Sqrat::RootTable().GetFunction("callEvent").Evaluate<bool>("onKeyUp", MOUSE_BUTTONMID);
			//	break;

			//case WM_XBUTTONDOWN:
			//	Sqrat::RootTable().GetFunction("callEvent").Evaluate<bool>("onKeyDown", pMouseHookStruct->mouseData);
			//	break;

			//case WM_XBUTTONUP:
			//	Sqrat::RootTable().GetFunction("callEvent").Evaluate<bool>("onKeyDown", pMouseHookStruct->mouseData);
			//	break;

			//case WM_MOUSEWHEEL:
			//{
			//	int zDelta = GET_WHEEL_DELTA_WPARAM(pMouseHookStruct->mouseData);
			//	Sqrat::RootTable().GetFunction("callEvent").Evaluate<bool>("onKeyDown", zDelta);
			//	break;
			//}
			//}
		}

		return CallNextHookEx(InputHandler::mouseHook, nCode, wParam, lParam);
	}

	HHOOK __stdcall SetWindowsHookExW_patch(int idHook, HOOKPROC lpfn, HINSTANCE hmod, DWORD dwThreadId);
	HOOK Ivk_SetWindowsHookExW AS(GetProcAddress(GetModuleHandleA("user32.dll"), "SetWindowsHookExW"), &SetWindowsHookExW_patch);
	HHOOK __stdcall SetWindowsHookExW_patch(int idHook, HOOKPROC lpfn, HINSTANCE hmod, DWORD dwThreadId)
	{
		Ivk_SetWindowsHookExW.Detach();
		const HHOOK result = nullptr;
		Ivk_SetWindowsHookExW.Attach();

		return result;
	}

	InputHandler::InputHandler()
	{
		keyboardHook = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, hInstApp, GetCurrentThreadId());
		mouseHook = SetWindowsHookEx(WH_MOUSE, MouseProc, hInstApp, GetCurrentThreadId());

		g2o::ClientEventHandlers::onExitHandler.emplace_back([]
			{
				UnhookWindowsHookEx(keyboardHook);
				UnhookWindowsHookEx(mouseHook);
			});
	}
}
