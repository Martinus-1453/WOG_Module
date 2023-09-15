#include "LauncherEnums.h"

#define STRINGIFY(s) #s
#define TO_STRING(s) STRINGIFY(s)

namespace wog::launcher
{
	const char* getMessageTypeName(const MessageType type)
	{
		switch (type)
		{
		case MessageType::Callback:
			return MESSAGE_TYPE_CALLBACK;
		case MessageType::Getter:
			return MESSAGE_TYPE_GETTER;
		case MessageType::Setter:
			return MESSAGE_TYPE_SETTER;
		}
		return "ERROR";
	}
}
