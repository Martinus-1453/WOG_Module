#ifndef WOG_CLIENT_BROWSER_H
#define WOG_CLIENT_BROWSER_H
#include <array>

#include "WogHeader.h"
#include "View.h"
#include "include/cef_app.h"
#include "include/cef_client.h"
#include "include/cef_render_handler.h"

namespace wog
{
	class Browser : public View, protected CefClient, protected CefRenderHandler, protected CefLifeSpanHandler
	{
	public:
		IMPLEMENT_REFCOUNTING(Browser);

		Browser(int x, int y, int width, int height, const char* url);
		~Browser() override;

		bool setUrl(const char* url) const;

		const char* getUrl() const;

		static void processKeyboardEvents(const CefKeyEvent& keyEvent);

	protected:
		CefRefPtr<CefRenderHandler> GetRenderHandler() override;
		CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override;

		void GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect) override;
		void OnAfterCreated(CefRefPtr<CefBrowser> browser) override;
		void OnBeforeClose(CefRefPtr<CefBrowser> browser) override;
		void OnPaint(CefRefPtr<CefBrowser> browser, PaintElementType type, const RectList& dirtyRects, const void* buffer, int width, int height) override;

	private:
		void clearBuffer() const;
		void initTexture();
		void correctPow2(int& xsize, int& ysize);
		void sendMouseClickEvent(Int key, bool isUp);
		void sendMouseMoveEvent(Int x, Int y);
		void sendMouseWheelEvent(Int z);

		CefRefPtr<CefBrowser> browser;
		bool isClosing;

		static inline std::vector<Browser*> objectList;
		std::array<bool, 3> mouseFlags{false};
		std::pair<Int, Int> mousePos{0, 0};
	};
}

#endif