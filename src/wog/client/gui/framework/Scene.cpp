#include "Scene.h"
#include "component/Canvas.h"

namespace wog::gui
{
	Scene::Scene()
	{
		root = std::make_unique<Canvas>();
	}
}
