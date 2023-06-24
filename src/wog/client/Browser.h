#ifndef WOG_CLIENT_BROWSER_H
#define WOG_CLIENT_BROWSER_H
#include "WogHeader.h"
#include "View.h"
#include "include/cef_app.h"
#include "include/cef_client.h"
#include "include/cef_render_handler.h"

namespace wog
{
	class Browser : public View, protected CefClient, protected CefRenderHandler, protected CefLifeSpanHandler
	{
		IMPLEMENT_REFCOUNTING(Browser);

	public:
		Browser(int x, int y, int width, int height, const char* url);
		virtual ~Browser();

		bool setUrl(const char* url);

		const char* getUrl();

	protected:
		virtual CefRefPtr<CefRenderHandler> GetRenderHandler() override;
		virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override;

		virtual void GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect) override;
		virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) override;
		virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) override;
		virtual void OnPaint(CefRefPtr<CefBrowser> browser, CefRenderHandler::PaintElementType type, const CefRenderHandler::RectList& dirtyRects, const void* buffer, int width, int height) override;
	
	private:
		void clearBuffer();
		void initTextureFormat();
		void correctPow2(int& xsize, int& ysize);

		zCTextureConvert* _texConverter;
		unsigned long _scaleFormat;

		CefRefPtr<CefBrowser> _browser;
		bool _closing;
		
	};
}

#endif