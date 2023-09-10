#include "CCefApp.h"

#include <include/cef_base.h>
#include "include/cef_app.h"
#include "include/cef_client.h"
#include "include/wrapper/cef_message_router.h"

#include "CefValueConverter.h"
#include "LauncherEnums.h"

namespace wog::launcher
{
    CefRefPtr<CefRenderProcessHandler> CCefApp::GetRenderProcessHandler()
    {
        return this;
    }

    void CCefApp::OnContextCreated(CefRefPtr<CefBrowser> browser, const CefRefPtr<CefFrame> frame,
        const CefRefPtr<CefV8Context> context)
    {
    }

    bool CCefApp::handleSetValueMessage(const CefRefPtr<CefFrame>& frame, const CefRefPtr<CefListValue>& arguments)
    {
        const auto objectPath = arguments->GetValue(0);
        const auto context = frame->GetV8Context();

        if (arguments->GetSize() < 2) return false;

        if (objectPath->GetType() == VTYPE_STRING)
        {
            //TODO: CHANGE THIS TO BE MORE FLEXIBLE
            const auto valueRef = context->GetGlobal()->GetValue(OBJECT_G2O);
            const auto elementName = objectPath->GetString();
            const auto value = arguments->GetValue(1);

            context->Enter();
            valueRef->SetValue(elementName, CefValueToCefV8Value(value), V8_PROPERTY_ATTRIBUTE_NONE);
            context->Exit();

            return true;
        }

        if (objectPath->GetType() != VTYPE_LIST) return false;

        const auto objectPathList = arguments->GetList(0);
        const auto objectPathSize = objectPathList->GetSize();

        if (objectPathSize < 1) return false;

        context->Enter();

        //TODO: CHANGE THIS TO BE MORE FLEXIBLE
        auto valueRef = context->GetGlobal()->GetValue(OBJECT_G2O);

        for (size_t i = 0; i < objectPathSize - 1; ++i)
        {
	        auto elementName = objectPathList->GetString(i);

	        if (elementName.empty())
	        {
		        context->Exit();
		        return false;
	        }

	        valueRef = valueRef->GetValue(elementName);

	        if (valueRef == nullptr)
	        {
		        context->Exit();
		        return false;
	        }
        }

        const auto elementName = objectPathList->GetString(objectPathSize - 1);
        const auto value = arguments->GetValue(1);

        valueRef->SetValue(elementName, CefValueToCefV8Value(value), V8_PROPERTY_ATTRIBUTE_NONE);
        context->Exit();
        return true;
    }

    bool CCefApp::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, const CefRefPtr<CefFrame> frame,
                                           CefProcessId sourceProcess, const CefRefPtr<CefProcessMessage> message)
    {
	    const auto arguments = message->GetArgumentList();

        if (!arguments || arguments->GetSize() == 0)
        {
            return false;
        }

		if (message->GetName() == MESSAGE_TYPE_CALLBACK)
		{
			const auto functionName = arguments->GetString(0);

			const auto context = frame->GetV8Context();
            context->Enter();

			if (const auto functionObject = context->GetGlobal()->GetValue(OBJECT_G2O)->GetValue(functionName))
            {
                // TODO: IMPLEMENT EXECUTING JS FUNCTION
            }
            else
            {
                return false;
            }

            context->Exit();
			return true;
		}

		if (message->GetName() == MESSAGE_TYPE_GETTER)
		{
            //TODO: IMPLEMENT GETTING VALUE FROM JS

            return true;
		}

		if (message->GetName() == MESSAGE_TYPE_SETTER)
		{
            return handleSetValueMessage(frame, arguments);
		}

        return false;
    }
}