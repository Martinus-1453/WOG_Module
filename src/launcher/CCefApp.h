#ifndef _CEF_CLASS_APP_H
#define _CEF_CLASS_APP_H

#include <include/cef_app.h>
#include "CV8Handler.h"

namespace wog::launcher
{
	class CCefApp : public CefApp, protected CefRenderProcessHandler
	{
	public:
		CCefApp() = default;

	protected:
		CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override;

		void OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context) override;
		static bool handleSetValueMessage(const CefRefPtr<CefFrame>& frame, const CefRefPtr<CefListValue>& arguments);
		bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefProcessId sourceProcess, CefRefPtr<CefProcessMessage> message) override;

	private:
		static void triggerCallback(CefRefPtr<CefFrame> frame, const CefV8ValueList& arguments);
		static void bindFunction(CefRefPtr<CefV8Value> context, CefRefPtr<CefFrame> frame, const char* name, JavascriptCallback callback);

		static CefRefPtr<CefProcessMessage> createMessage(const char* name, const CefV8ValueList& arguments);
		static std::string argumentToString(CefRefPtr<CefV8Value> cefValue);

		IMPLEMENT_REFCOUNTING(CCefApp);
		DISALLOW_COPY_AND_ASSIGN(CCefApp);
	};
}
#endif
