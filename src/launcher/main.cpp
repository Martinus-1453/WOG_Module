#pragma comment (lib, "libcef.lib")

#include <Windows.h>
#include "CCefApp.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdShow, int nCmdShow)
{
    // Load CEF
    const CefMainArgs mainArgs(hInstance);
    const CefRefPtr app { new wog::launcher::CCefApp };

    return CefExecuteProcess(mainArgs, app, nullptr);
}
