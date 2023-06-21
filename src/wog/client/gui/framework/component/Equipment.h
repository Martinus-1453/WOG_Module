#ifndef WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_EQUIPMENT_H_
#define WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_EQUIPMENT_H_

#include "Equipment.h"
#include "List.h"

namespace wog::gui
{
	class Equipment : public List
	{
	public:
		Equipment();
		Equipment(Int x, Int y, const Coord& elementSize);
		~Equipment() override = default;

	protected:
		Image* draggedImage{ nullptr };
	};
}

#endif // WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_EQUIPMENT_H_