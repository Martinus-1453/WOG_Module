#ifndef WOG_CLIENT_BROWSER_H
#define WOG_CLIENT_BROWSER_H
#include <array>

#include "WogHeader.h"
#include "View.h"
#include "include/cef_app.h"
#include "include/cef_client.h"
#include "include/cef_render_handler.h"
#include "include/wrapper/cef_message_router.h"
#include <include/wrapper/cef_resource_manager.h>

namespace wog
{
	class Browser :
		public View,
		protected CefClient,
		protected CefRenderHandler,
		protected CefLifeSpanHandler,
		protected CefRequestHandler,
		public CefResourceRequestHandler
	{
	public:
		IMPLEMENT_REFCOUNTING(Browser);

		Browser(int x, int y, int width, int height, const char* url);
		~Browser() override;

		bool setUrl(const char* url) const;

		const char* getUrl() const;

		static void processKeyboardEvents(const CefKeyEvent& keyEvent);

		static inline std::vector<Browser*> objectList;
		CefRefPtr<CefBrowser> browser;

	protected:
		CefRefPtr<CefRenderHandler> GetRenderHandler() override;
		CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override;
		CefRefPtr<CefResourceHandler> GetResourceHandler(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefRequest> request) override;
		CefRefPtr<CefResourceRequestHandler> GetResourceRequestHandler(
			CefRefPtr<CefBrowser> /*browser*/,
			CefRefPtr<CefFrame> /*frame*/,
			CefRefPtr<CefRequest> /*request*/,
			bool /*is_navigation*/,
			bool /*is_download*/,
			const CefString& /*request_initiator*/,
			bool& /*disable_default_handling*/) override;
		CefRefPtr<CefRequestHandler> GetRequestHandler() override;

		cef_return_value_t OnBeforeResourceLoad(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefRequest> request, CefRefPtr<CefRequestCallback> callback) override;


		bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefProcessId source_process, CefRefPtr<CefProcessMessage> message) override;
		void GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect) override;
		void OnAfterCreated(CefRefPtr<CefBrowser> browser) override;
		void OnBeforeClose(CefRefPtr<CefBrowser> browser) override;
		void OnPaint(CefRefPtr<CefBrowser> browser, PaintElementType type, const RectList& dirtyRects, const void* buffer, int width, int height) override;

	private:
		void clearBuffer() const;
		void initTexture();
		static void correctPow2(int& xSize, int& ySize);
		void sendMouseClickEvent(Int key, bool isUp);
		void sendMouseMoveEvent(Int x, Int y);
		void sendMouseWheelEvent(Int z);

		bool isClosing;

		CefRefPtr<CefResourceManager> m_resourceManager;

		std::array<bool, 3> mouseFlags{false};
		std::pair<Int, Int> mousePos{0, 0};
	};
}

#endif