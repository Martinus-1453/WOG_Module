#pragma once
#ifndef SHARED_FUNCTIONS_H
#define SHARED_FUNCTIONS_H
#include "Function.h"
#include "CustomTypes.h"

#define SHARED_FUNCTIONS nonut::g2o::SharedFunctions::getInstance()

namespace nonut::g2o
{
	class SharedFunctions
	{
	protected:
		SharedFunctions();
		static SharedFunctions* instance;
	public:
		SharedFunctions(SharedFunctions& other) = delete;
		void operator=(const SharedFunctions&) = delete;
		static SharedFunctions* getInstance();

		// G2O functions
		Function<void, String> print;
	};
}
#endif
