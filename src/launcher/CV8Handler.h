#ifndef _CEF_CLASS_HANDLER_H
#define _CEF_CLASS_HANDLER_H

#include <include/cef_app.h>

typedef void (*JavascriptCallback)(CefRefPtr<CefFrame> frame, const CefV8ValueList& arguments);

class CV8Handler : public CefV8Handler
{
	IMPLEMENT_REFCOUNTING(CV8Handler);
public:
    CV8Handler(CefRefPtr<CefFrame> frame);

    void Bind(const std::string& name, JavascriptCallback callback);
    void Clear();

protected:
    virtual bool Execute(const CefString& name, CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception) override;

private:
    CefRefPtr<CefFrame> _frame;
    std::map<std::string, JavascriptCallback> _functionMap;
};

#endif