#ifndef WOG_CLIENT_GUI_FRAMEWORK_EVENT_HANDLER_H
#define WOG_CLIENT_GUI_FRAMEWORK_EVENT_HANDLER_H

#include <functional>
#include <set>

#include "Object.h"
#include "CommonHeader.h"

namespace wog::gui
{
	class EventHandler final : public Singleton<EventHandler>
	{
	public:
		std::unordered_map<Object*, std::function<void(Int)>> onMouseClickMap{};
		std::unordered_map<Object*, std::function<void(Int)>> onMouseReleaseMap{};
		std::unordered_map<Object*, std::function<void(Int, Int, Int)>> onMouseMoveMap{};
		std::unordered_map<Object*, std::function<void(Int, Int)>> onMouseHooverInMap{};
		std::unordered_map<Object*, std::function<void(Int, Int)>> onMouseHooverOutMap{};
		std::unordered_map<Object*, std::function<void(Int)>> onMouseWheelMap{};

	private:
		EventHandler();

		Object* focusedObject = nullptr;
		Object* hooverObject = nullptr;
		Int focusedKey = -1;

		friend Singleton;
	};
}
#endif // WOG_CLIENT_GUI_FRAMEWORK_EVENT_HANDLER_H
