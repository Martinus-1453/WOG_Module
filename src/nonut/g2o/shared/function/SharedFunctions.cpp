#include "SharedFunctions.h"

namespace nonut::g2o
{
	SharedFunctions* SharedFunctions::instance = nullptr;

	SharedFunctions::SharedFunctions() :
		FUNCTION_CTOR(print)
	{
	}

	SharedFunctions* SharedFunctions::getInstance()
	{
		if (instance == nullptr)
		{
			instance = new SharedFunctions();
		}
		return instance;
	}
}
