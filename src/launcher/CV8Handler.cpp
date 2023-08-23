#include "CV8Handler.h"

CV8Handler::CV8Handler(CefRefPtr<CefFrame> frame)
	: _frame(frame)
{
}

void CV8Handler::Bind(const std::string& name, JavascriptCallback callback)
{
    _functionMap[name] = callback;
}

void CV8Handler::Clear()
{
    _functionMap.clear();
}

bool CV8Handler::Execute(const CefString& name, CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception)
{
    std::map<std::string, JavascriptCallback>::iterator iter = _functionMap.find(std::string(name));

    if (iter != _functionMap.end())
    {
        iter->second(_frame, arguments);
        return true;
    }

    return false;
}
