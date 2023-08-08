#include "CCefApp.h"

#include <iostream>
#include <include/cef_base.h>
#include "include/cef_app.h"
#include "include/cef_client.h"
#include "include/cef_render_handler.h"
#include "include/wrapper/cef_message_router.h"
#include <include/wrapper/cef_resource_manager.h>

CefRefPtr<CefRenderProcessHandler> CCefApp::GetRenderProcessHandler()
{
	return this;
}

void CCefApp::OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context)
{
	CefRefPtr<CefV8Value> global = context->GetGlobal();
	CefRefPtr<CefV8Value> g2o = CefV8Value::CreateObject(nullptr, nullptr);
    auto str = CefV8Value::CreateString("BEP!");
    auto frameName = frame->GetName();
    std::cout <<  "Framename: " << frameName << std::endl;

    bindFunction(g2o, frame, "triggerEvent", CCefApp::triggerEvent);
	global->SetValue("g2o", g2o, V8_PROPERTY_ATTRIBUTE_NONE);

    auto msg = CefProcessMessage::Create("chleb");
    frame->SendProcessMessage(PID_BROWSER, msg);
}

bool CCefApp::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefProcessId source_process, CefRefPtr<CefProcessMessage> message)
{
    if (message->GetName() == "chleb")
    {
        auto str = CefV8Value::CreateString("bep!");
        auto context = frame->GetV8Context();
        context->Enter();
        context->GetGlobal()->SetValue("chleb", str, V8_PROPERTY_ATTRIBUTE_NONE);
        context->Exit();
        return true;
    }

    return false;
}

void CCefApp::triggerEvent(CefRefPtr<CefFrame> frame, const CefV8ValueList& arguments)
{
    if (arguments.size() == 0)
        return;

    CefRefPtr<CefProcessMessage> message = createMessage("triggerEvent", arguments);
	frame->GetBrowser()->GetMainFrame()->SendProcessMessage(PID_BROWSER, message);
}

void CCefApp::bindFunction(CefRefPtr<CefV8Value> context, CefRefPtr<CefFrame> frame, const char* name, JavascriptCallback callback)
{
    CefRefPtr<CV8Handler> handler = new CV8Handler(frame);
    handler->Bind(name, callback);

    CefRefPtr<CefV8Value> function = CefV8Value::CreateFunction(name, handler);

    context->SetValue(name, function, V8_PROPERTY_ATTRIBUTE_NONE);
}

CefRefPtr<CefProcessMessage> CCefApp::createMessage(const char* name, const CefV8ValueList& arguments)
{
    // Create the process message
    CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(name);
    CefRefPtr<CefListValue> argList = message->GetArgumentList();

    // Write the event name
    argList->SetString(0, arguments[0]->GetStringValue());

    // Write number of arguments
    argList->SetInt(1, arguments.size() - 1);

    // Write arguments
    for (size_t i = 1; i < arguments.size(); ++i)
    {
        std::string argument = argumentToString(arguments[i]);
        argList->SetString(i + 1, argument);
    }

    return message;
}

std::string CCefApp::argumentToString(CefRefPtr<CefV8Value> cefValue)
{
    std::stringstream conversionStream;
    conversionStream.str("");
    conversionStream.clear();

    if (cefValue->IsBool())
        conversionStream << cefValue->GetBoolValue();
    else if (cefValue->IsDouble())
        conversionStream << cefValue->GetDoubleValue();
    else if (cefValue->IsInt())
        conversionStream << cefValue->GetIntValue();
    else if (cefValue->IsNull())
        conversionStream << "nil";
    else if (cefValue->IsString())
        conversionStream << std::string(cefValue->GetStringValue());
    else if (cefValue->IsUInt())
        conversionStream << cefValue->GetUIntValue();
    else
        conversionStream << "unsupported type";

    return conversionStream.str();
}
