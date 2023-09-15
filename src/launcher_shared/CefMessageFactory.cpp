#include "CefMessageFactory.h"

#include "Browser.h"

namespace wog::launcher
{
	CefMessageFactory::CefMessageFactory(const MessageType type)
	{
		message = CefProcessMessage::Create(getMessageTypeName(type));
		message->GetArgumentList()->SetSize(2);
	}

	CefMessageFactory& CefMessageFactory::setPath(const String& path)
	{
		const auto argList = message->GetArgumentList();

		argList->SetString(0, path);

		return *this;
	}

	CefMessageFactory& CefMessageFactory::setPath(const Vector<String>& pathVector)
	{
		const auto argList = message->GetArgumentList();
		const auto pathList = CefListValue::Create();

		size_t i = 0;
		for (auto&& pathPart : pathVector)
		{
			pathList->SetString(i, pathPart);
			++i;
		}
		argList->SetList(0, pathList);

		return *this;
	}

	CefMessageFactory& CefMessageFactory::setValue(const CefRefPtr<CefValue>& value)
	{
		const auto argList = message->GetArgumentList();

		argList->SetValue(1, value);

		return *this;
	}

	void CefMessageFactory::send() const
	{
		for (auto && object : Browser::objectList)
		{
			object->browser->GetMainFrame()->SendProcessMessage(PID_BROWSER, message);
		}
	}
}
