#include "CommonHeader.h"
#include "function/ClientFunctions.h"
#include "ClientInit.h"
#include "WogConfig.h"
#include "class/ui/Draw.h"
#include "Virt.h"
#include "class/game/World.h"
#include "Browser.h"

using namespace SqModule;

wog::View* testView;

extern "C" SQRESULT SQRAT_API sqmodule_load(HSQUIRRELVM vm, HSQAPI api)
{
	//Setup CEF

	Initialize(vm, api);
	Sqrat::DefaultVM::Set(vm);
	C_F->enableEvent_Render(true);
	wog::clientInit();

	// Test print function
	SH_F->print("Nonut module initialized");

	// Draw module version and build time in the corner
	const std::string corner_message = "WoG v" + std::to_string(wog_module_VERSION_MAJOR) + "." +
		std::to_string(wog_module_VERSION_MINOR) + " - " + wog_module_COMPILE_TIME_str;
	const auto draw = new g2o::Draw(g2o::Virt(0.2f), g2o::Virt(0.97f), corner_message);
	// TODO: consider having unique_ptr in some singleton to hold it?
	draw->visible = true;
	draw->setScale(1, 1);

	//CEF - Init
	CefMainArgs args;
	CefSettings settings;

	std::string systemDir = zoptions->GetDirString(DIR_EXECUTABLE).ToChar();

	CefString(&settings.browser_subprocess_path).FromString(systemDir + "/cef_launcher.exe");
	CefString(&settings.resources_dir_path).FromString(systemDir + "/CEF");
	CefString(&settings.locales_dir_path).FromString(systemDir + "/CEF/locales");
	CefString(&settings.log_file).FromString(systemDir + "/CEF/log.txt");

	settings.windowless_rendering_enabled = true;
	settings.no_sandbox = true;

	CefInitialize(args, settings, nullptr, nullptr);

	g2o::ClientEventHandlers::onRenderHandler.emplace_back([](nonut::Float delta) {
		CefDoMessageLoopWork();
	});

	//CEF - Enum Texture Formats
	zCRnd_D3D* render_d3d = reinterpret_cast<zCRnd_D3D*>(zrenderer);
	LPD3DENUMPIXELFORMATSCALLBACK textureCallback = (LPD3DENUMPIXELFORMATSCALLBACK)0x00647780;
	int StartFormat;

	render_d3d->xd3d_pd3dDevice7->EnumTextureFormats(textureCallback, static_cast<LPVOID>(&StartFormat));

	//CEF - Test
	testView = new wog::Browser(0, 0, 2196, 2196, "https://google.com/");
	testView->setVisible(true);

	return SQ_OK;
}
