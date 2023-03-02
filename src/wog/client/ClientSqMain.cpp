#include "pch.h"
#include "function/ClientFunctions.h"
#include "ClientInit.h"
#include "WogConfig.h"
#include "class/ui/Draw.h"
#include "Virt.h"
#include "class/math/Vec3.h"

using namespace SqModule;

extern "C" SQRESULT SQRAT_API sqmodule_load(HSQUIRRELVM vm, HSQAPI api)
{
	Initialize(vm, api);
	Sqrat::DefaultVM::Set(vm);
	C_F->enableEvent_Render(true);
	wog::clientInit();

	// Test print function
	SH_F->print("Print z szablonu :D");

	// Draw module version and build time in the corner
	const std::string corner_message = "WoG v" + std::to_string(wog_module_VERSION_MAJOR) + "." +
									   std::to_string(wog_module_VERSION_MINOR) + " - " + wog_module_COMPILE_TIME_str;
	const auto draw = new nonut::g2o::Draw(nonut::g2o::Virt(0.2f), nonut::g2o::Virt(0.97f), corner_message); // TODO: consider having unique_ptr in some singleton to hold it?
	draw->visible = true;
	draw->setScale(1, 1);

	nonut::g2o::Vec3 v0(0);
	nonut::g2o::Vec3 v1(1.f);
	nonut::g2o::Vec3 v2(-0.5f);
	//auto v3 = v0.dot(v1, v2);
	//v1 = v2;
	auto v4 = v1.normalize();
	//v1.swap(v1, v2);
	SH_F->print(std::to_string(v4.x));
	//SH_F->print("v1=" + std::to_string(v1.x));
	//SH_F->print("v2=" + std::to_string(v2.x));
	//SH_F->print("v3=" + std::to_string(v3));

	return SQ_OK;
}
