#ifndef LAUNCHER_SHARED_CEFVALUECONVERTER_H_
#define LAUNCHER_SHARED_CEFVALUECONVERTER_H_

#include "include/cef_v8.h"
#include "include/internal/cef_ptr.h"

namespace wog::launcher
{
    CefRefPtr<CefV8Value> CefValueToCefV8Value(const CefRefPtr<CefValue>& value);
}
#endif // LAUNCHER_SHARED_CEFVALUECONVERTER_H_
