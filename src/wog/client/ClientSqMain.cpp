#include "pch.h"
#include "function/ClientFunctions.h"
#include "ClientInit.h"

using namespace SqModule;

extern "C" SQRESULT SQRAT_API sqmodule_load(HSQUIRRELVM vm, HSQAPI api)
{
	Initialize(vm, api);
	Sqrat::DefaultVM::Set(vm);

	wog::init();

	// Test print function
	CLIENT_FUNCTIONS->print("Print z szablonu :D");

	// Test getWorld function + print
	CLIENT_FUNCTIONS->print(CLIENT_FUNCTIONS->getWorld());

	return SQ_OK;
}
