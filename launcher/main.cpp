#pragma comment (lib, "libcef.lib")

#include <Windows.h>
#include "CCefApp.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdShow, int nCmdShow)
{
    // Load CEF
    CefMainArgs main_args(hInstance);
    CefRefPtr<CCefApp> app { new CCefApp };

    return CefExecuteProcess(main_args, app, nullptr);
}
