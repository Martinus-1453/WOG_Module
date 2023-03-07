#include "pch.h"
#include "function/ClientFunctions.h"
#include "ClientInit.h"
#include "UserData.h"
#include "WogConfig.h"
#include "class/ui/Draw.h"
#include "Virt.h"
#include "class/game/World.h"
#include "class/math/Vec3.h"

using namespace SqModule;

extern "C" SQRESULT SQRAT_API sqmodule_load(HSQUIRRELVM vm, HSQAPI api)
{
	Initialize(vm, api);
	Sqrat::DefaultVM::Set(vm);
	C_F->enableEvent_Render(true);
	wog::clientInit();

	// Test print function
	SH_F->print("Nonut module initialized");

	// Draw module version and build time in the corner
	const std::string corner_message = "WoG v" + std::to_string(wog_module_VERSION_MAJOR) + "." +
									   std::to_string(wog_module_VERSION_MINOR) + " - " + wog_module_COMPILE_TIME_str;
	const auto draw = new nonut::g2o::Draw(nonut::g2o::Virt(0.2f), nonut::g2o::Virt(0.97f), corner_message); // TODO: consider having unique_ptr in some singleton to hold it?
	draw->visible = true;
	draw->setScale(1, 1);

	return SQ_OK;
}
