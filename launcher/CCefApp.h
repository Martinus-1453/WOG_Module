#ifndef _CEF_CLASS_APP_H
#define _CEF_CLASS_APP_H

#include <include/cef_app.h>
#include "CV8Handler.h"

class CCefApp : public CefApp, protected CefRenderProcessHandler
{
	IMPLEMENT_REFCOUNTING(CCefApp);
public:
	CCefApp() {}

protected:
	virtual CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override;
	virtual void OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context) override;

private:
	static void triggerEvent(CefRefPtr<CefFrame> frame, const CefV8ValueList& arguments);
	static void bindFunction(CefRefPtr<CefV8Value> context, CefRefPtr<CefFrame> frame, const char* name, JavascriptCallback callback);

	static CefRefPtr<CefProcessMessage> createMessage(const char* name, const CefV8ValueList& arguments);
	static std::string argumentToString(CefRefPtr<CefV8Value> cefValue);
};

#endif