#pragma once
#include "pch.h"
#include "ClientEventHandlers.h"

using namespace SqModule;

namespace wog
{
	inline void Init()
	{
		//TODO: REMOVE SQRAT DEPENDENCY
		Sqrat::RootTable(vm).Func("testHandler", &onKey);

		nonut::Function<void, std::string, HSQOBJECT, int> addEventHandler("addEventHandler");
		nonut::Function<void, int> testHandler("testHandler");
		addEventHandler("onKey", testHandler.GetObject(), 1);
	}
}
