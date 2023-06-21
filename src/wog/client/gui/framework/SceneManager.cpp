#include "SceneManager.h"
#include <ranges>

namespace wog::gui
{
	Object* SceneManager::collide(Coord pos)
	{
		Object* result = nullptr;

		for (const auto& scene : std::views::reverse(scenes) | std::views::values)
		{
			if (!scene.root->isEnabled()) continue;
			result = scene.root->getFirstCollision(pos);
			if (result != nullptr)
			{
				break;
			}
		}

		return result;
	}
}
