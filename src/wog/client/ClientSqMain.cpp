#include "pch.h"
#include "SquirrelTemplateConfig.h"
#include "nonut/g2o/client/class/Draw.h"
#include "nonut/g2o/client/function/ClientFunctions.h"
#include "wog/client/ClientInit.h"

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

	// Test Draw class
	const std::string corner_message = std::to_string(squirrel_template_VERSION_MAJOR) + "." +
		std::to_string(squirrel_template_VERSION_MINOR) + " - " + squirrel_template_COMPILE_TIME_str;
	const auto draw = new nonut::g2o::Draw(0, 0, corner_message);


	draw->visible.set(true);
	return SQ_OK;
}
