#include "Browser.h"
#include "Hook.h"
#include "include/internal/cef_types.h"
#include "include/internal/cef_types_wrappers.h"

bool isKeyDown(WPARAM wParam)
{
    return (GetKeyState(wParam) & 0x8000) != 0;
}

int GetCefKeyboardModifiers(WPARAM wParam, LPARAM lParam)
{
    int modifiers = 0;
    if (isKeyDown(VK_SHIFT))
        modifiers |= EVENTFLAG_SHIFT_DOWN;
    if (isKeyDown(VK_CONTROL))
        modifiers |= EVENTFLAG_CONTROL_DOWN;
    if (isKeyDown(VK_MENU))
        modifiers |= EVENTFLAG_ALT_DOWN;

    // Low bit set from GetKeyState indicates "toggled".
    if (::GetKeyState(VK_NUMLOCK) & 1)
        modifiers |= EVENTFLAG_NUM_LOCK_ON;
    if (::GetKeyState(VK_CAPITAL) & 1)
        modifiers |= EVENTFLAG_CAPS_LOCK_ON;

    switch (wParam)
    {
    case VK_RETURN:
        if ((lParam >> 16) & KF_EXTENDED)
            modifiers |= EVENTFLAG_IS_KEY_PAD;
        break;
    case VK_INSERT:
    case VK_DELETE:
    case VK_HOME:
    case VK_END:
    case VK_PRIOR:
    case VK_NEXT:
    case VK_UP:
    case VK_DOWN:
    case VK_LEFT:
    case VK_RIGHT:
        if (!((lParam >> 16) & KF_EXTENDED))
            modifiers |= EVENTFLAG_IS_KEY_PAD;
        break;
    case VK_NUMLOCK:
    case VK_NUMPAD0:
    case VK_NUMPAD1:
    case VK_NUMPAD2:
    case VK_NUMPAD3:
    case VK_NUMPAD4:
    case VK_NUMPAD5:
    case VK_NUMPAD6:
    case VK_NUMPAD7:
    case VK_NUMPAD8:
    case VK_NUMPAD9:
    case VK_DIVIDE:
    case VK_MULTIPLY:
    case VK_SUBTRACT:
    case VK_ADD:
    case VK_DECIMAL:
    case VK_CLEAR:
        modifiers |= EVENTFLAG_IS_KEY_PAD;
        break;
    case VK_SHIFT:
        if (isKeyDown(VK_LSHIFT))
            modifiers |= EVENTFLAG_IS_LEFT;
        else if (isKeyDown(VK_RSHIFT))
            modifiers |= EVENTFLAG_IS_RIGHT;
        break;
    case VK_CONTROL:
        if (isKeyDown(VK_LCONTROL))
            modifiers |= EVENTFLAG_IS_LEFT;
        else if (isKeyDown(VK_RCONTROL))
            modifiers |= EVENTFLAG_IS_RIGHT;
        break;
    case VK_MENU:
        if (isKeyDown(VK_LMENU))
            modifiers |= EVENTFLAG_IS_LEFT;
        else if (isKeyDown(VK_RMENU))
            modifiers |= EVENTFLAG_IS_RIGHT;
        break;
    case VK_LWIN:
        modifiers |= EVENTFLAG_IS_LEFT;
        break;
    case VK_RWIN:
        modifiers |= EVENTFLAG_IS_RIGHT;
        break;
    }
    return modifiers;
}

LRESULT CALLBACK Hook_AppWndProc(HWND hwnd, zUWORD msg, WPARAM wParam, LPARAM lParam);
HOOK Ivk_AppWndProc AS(0x00503770, Hook_AppWndProc);
LRESULT CALLBACK Hook_AppWndProc(HWND hwnd, zUWORD msg, WPARAM wParam, LPARAM lParam)
{
	Ivk_AppWndProc.Detach();

	switch (msg)
	{
	case WM_KEYDOWN:
	case WM_KEYUP:
	case WM_CHAR:
	{
        CefKeyEvent keyEvent;
        keyEvent.windows_key_code = wParam;
        keyEvent.native_key_code = lParam;
        keyEvent.modifiers = GetCefKeyboardModifiers(wParam, lParam);
        keyEvent.is_system_key = msg == WM_SYSCHAR || msg == WM_SYSKEYDOWN || msg == WM_SYSKEYUP;

        if (msg == WM_KEYDOWN || msg == WM_SYSKEYDOWN)
            keyEvent.type = KEYEVENT_RAWKEYDOWN;
        else if (msg == WM_KEYUP || msg == WM_SYSKEYUP)
            keyEvent.type = KEYEVENT_KEYUP;
        else if (msg == WM_CHAR || msg == WM_SYSCHAR)
            keyEvent.type = KEYEVENT_CHAR;

        // Alt-Gr check
        if ((keyEvent.type == KEYEVENT_CHAR) && isKeyDown(VK_RMENU))
        {
			const HKL   currentLayout = GetKeyboardLayout(0);
			const SHORT scanRes = VkKeyScanExW(wParam, currentLayout);
            if ((HIBYTE(scanRes) & (2 | 4)) == (2 | 4))
            {
                keyEvent.modifiers &= ~(EVENTFLAG_CONTROL_DOWN | EVENTFLAG_ALT_DOWN);
                keyEvent.modifiers |= EVENTFLAG_ALTGR_DOWN;
            }
        }

        wog::Browser::processKeyboardEvents(keyEvent);

		break;
	}
	}

	const LRESULT result = Ivk_AppWndProc(hwnd, msg, wParam, lParam);

	Ivk_AppWndProc.Attach();

	return result;
}