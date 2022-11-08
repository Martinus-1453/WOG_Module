#include "pch.h"
#include "nonut/Function.h"
#include "nonut/g2o/Draw.h"
#include "wog/Init.h"
using namespace SqModule;

extern "C" SQRESULT SQRAT_API sqmodule_load(HSQUIRRELVM vm, HSQAPI api) {
	Initialize(vm, api);
	Sqrat::DefaultVM::Set(vm);

	wog::Init();

	// Test print function
	nonut::Function<void, std::string> print("print");
	print(std::string("Print z szablonu :D"));

	// Test getWorld function + print
	nonut::Function<std::string> getWorld("getWorld");
	print(getWorld());

	// Test Draw class
	const auto draw = new nonut::g2o::Draw(0, 0, "dupa");
	draw->visible.Set(true);
	return SQ_OK;
}
