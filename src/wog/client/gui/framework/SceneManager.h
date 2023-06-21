#ifndef WOG_CLIENT_GUI_FRAMEWORK_SCENEMANAGER_H
#define WOG_CLIENT_GUI_FRAMEWORK_SCENEMANAGER_H

#include "CommonHeader.h"
#include <map>
#include "Scene.h"

namespace wog::gui
{
	class SceneManager
	{
	public:
		static inline std::map<size_t, Scene> scenes{};

		static Object* collide(Coord pos);

	};
}
#endif // WOG_CLIENT_GUI_FRAMEWORK_SCENEMANAGER_H
