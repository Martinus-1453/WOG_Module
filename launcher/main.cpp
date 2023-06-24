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

/*int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    
}*/