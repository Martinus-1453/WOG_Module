#ifndef LAUNCHER_SHARED_MESSAGEFACTORY_H_
#define LAUNCHER_SHARED_MESSAGEFACTORY_H_
#include "LauncherEnums.h"
#include "WogHeader.h"
#include "include/cef_process_message.h"

namespace wog::launcher
{
	class CefMessageFactory
	{
	public:
		CefMessageFactory(MessageType type);

		CefMessageFactory& setPath(const String& path);
		CefMessageFactory& setPath(const Vector<std::string>& pathVector);

		CefMessageFactory& setValue(const CefRefPtr<CefValue>& value);

		void send() const;

	private:
		CefRefPtr<CefProcessMessage> message;
	};
}
#endif // LAUNCHER_SHARED_MESSAGEFACTORY_H_