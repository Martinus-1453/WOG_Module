#include "CommonHeader.h"
#include "function/SharedFunctions.h"
#include "ServerInit.h"
#include "db/Database.h"

using namespace SqModule;

extern "C" SQRESULT SQRAT_API sqmodule_load(HSQUIRRELVM vm, HSQAPI api)
{
	Initialize(vm, api);
	Sqrat::DefaultVM::Set(vm);
	std::ignore = wog::Database::get();
	wog::serverInit();
	// Test print function
	SHARED_FUNCTIONS->print("Nonut module initialized!");
	return SQ_OK;
}
