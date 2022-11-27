#include "pch.h"
#include "function/ClientFunctions.h"
#include "ClientInit.h"
#include "WogConfig.h"
#include "class/Draw.h"

using namespace SqModule;

extern "C" SQRESULT SQRAT_API sqmodule_load(HSQUIRRELVM vm, HSQAPI api)
{
	Initialize(vm, api);
	Sqrat::DefaultVM::Set(vm);

	wog::clientInit();

	// Test print function
	SHARED_FUNCTIONS->print("Print z szablonu :D");

	// Test getWorld function + print
	SHARED_FUNCTIONS->print(CLIENT_FUNCTIONS->getWorld());

	// Draw module version and build time in the corner
	const std::string corner_message = "WoG v" + std::to_string(wog_module_VERSION_MAJOR) + "." +
									   std::to_string(wog_module_VERSION_MINOR) + " - " + wog_module_COMPILE_TIME_str;
	const auto draw = new nonut::g2o::Draw(0, 0, corner_message); // TODO: consider having unique_ptr in some singleton to hold it?
	draw->visible = true;

	return SQ_OK;
}
