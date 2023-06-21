#ifndef WOG_CLIENT_GUI_FRAMEWORK_SCENE_H
#define WOG_CLIENT_GUI_FRAMEWORK_SCENE_H

#include "CommonHeader.h"
#include <memory>
#include "Object.h"

namespace wog::gui
{
	class Scene
	{
	public:
		Scene();

		ObjectPtr root = nullptr;
	};
}
#endif // WOG_CLIENT_GUI_FRAMEWORK_SCENE_H
