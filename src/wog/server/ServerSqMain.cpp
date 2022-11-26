#include "pch.h"
#include "function/SharedFunctions.h"
#include "ServerInit.h"

using namespace SqModule;

extern "C" SQRESULT SQRAT_API sqmodule_load(HSQUIRRELVM vm, HSQAPI api)
{
	Initialize(vm, api);
	Sqrat::DefaultVM::Set(vm);

	wog::serverInit();

	// Test print function
	SHARED_FUNCTIONS->print("Print z szablonu :D");
	return SQ_OK;
}
