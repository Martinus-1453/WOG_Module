#ifndef NONUT_CORE_USER_DATA_H
#define NONUT_CORE_USER_DATA_H

#include "pch.h"

namespace nonut
{
	class UserData
	{
	public:
		SQUserPointer userPtr = nullptr;
		SQUserPointer tagPtr = nullptr;
	};
}
#endif //NONUT_CORE_INSTANCE_H