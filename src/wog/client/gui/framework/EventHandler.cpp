#include "EventHandler.h"

#include <ranges>

#include "SceneManager.h"
#include "event/ClientEventHandlers.h"
#include "function/ClientFunctions.h"
#include "function/SharedFunctions.h"

namespace wog::gui
{
	Object* findCollision()
	{
		auto [x, y] = C_F->getCursorPositionPx();
		const Coord mousePos(x, y);
		return SceneManager::collide(mousePos);
	}

	EventHandler::EventHandler() : Singleton()
	{
		g2o::ClientEventHandlers::onMouseClickHandler.emplace_back([this](const Int key)
			{
				// Process only when we have cursor visible
				if (!C_F->isCursorVisible()) return;
				// Process only when we don't have pending object
				if (focusedObject != nullptr && focusedKey != -1) return;

				Object* clickResult = findCollision();

				SH_F->print("Address of focused object: " + std::to_string(reinterpret_cast<size_t>(clickResult)));
				if (clickResult != nullptr)
				{
					auto [x,y] = clickResult->getPosition().getPx();
					auto [w, h] = clickResult->getSize().getPx();
					SH_F->print("Pos: " + std::to_string(x) + " " + std::to_string(y));
					SH_F->print("Size: " + std::to_string(w) + " " + std::to_string(h));
				}

				if (const auto clickLambda = onMouseClickMap.find(clickResult);
					clickLambda != onMouseClickMap.end())
				{
					focusedObject = clickResult;
					focusedKey = key;
					clickLambda->second(key);
				}
			});

		g2o::ClientEventHandlers::onMouseReleaseHandler.emplace_back([this](const Int key)
			{
				if (focusedObject != nullptr && focusedKey == key)
				{
					if (const auto releaseLambda = onMouseReleaseMap.find(focusedObject);
						releaseLambda != onMouseReleaseMap.end())
					{
						releaseLambda->second(key);
					}

					if (findCollision() == focusedObject)
					{
						hooverObject = focusedObject;
						if (const auto hooverInLambda = onMouseHooverInMap.find(focusedObject);
							hooverInLambda != onMouseHooverInMap.end())
						{
							hooverInLambda->second(0, 0);
						}
					}

					focusedObject = nullptr;
					focusedKey = -1;
				}
			});

		g2o::ClientEventHandlers::onMouseMoveHandler.emplace_back([this](const Int x, const Int y)
			{
				// Process only when we have cursor visible
				if (!C_F->isCursorVisible()) return;

				if (focusedObject != nullptr && focusedKey != -1)
				{
					if (const auto moveLambda = onMouseMoveMap.find(focusedObject);
						moveLambda != onMouseMoveMap.end())
					{
						moveLambda->second(focusedKey, x, y);
					}
				}
				else
				{
					const auto collision = findCollision();
					// Maybe support movement inside object
					if (hooverObject == collision) return;

					if (const auto hooverOutLambda = onMouseHooverOutMap.find(hooverObject);
						hooverOutLambda != onMouseHooverOutMap.end())
					{
						hooverOutLambda->second(x, y);
					}

					hooverObject = collision;

					if (const auto hooverInLambda = onMouseHooverInMap.find(collision);
						hooverInLambda != onMouseHooverInMap.end())
					{
						hooverInLambda->second(x, y);
					}

				}
			});

		g2o::ClientEventHandlers::onMouseWheelHandler.emplace_back([this](const Int z)
			{
				// Process only when we have cursor visible
				if (!C_F->isCursorVisible()) return;
				if (focusedObject != nullptr) return;

				if (const auto wheelLambda = onMouseWheelMap.find(findCollision());
					wheelLambda != onMouseWheelMap.end())
				{
					wheelLambda->second(z);
				}
			});
	}
}
