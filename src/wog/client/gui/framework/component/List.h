#ifndef WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_LIST_H
#define WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_LIST_H
#include "Button.h"
#include "gui/framework/Object.h"

namespace wog::gui
{
	class List : public Object
	{
	public:
		List();
		List(Int columns, Int rows, const Coord& elementSize);

		void update() override;
		void top() override;
		void setEnabled(bool value) override;
		void setVisible(bool value) override;
		void setCollision(bool value) override;
		void setPosition(Coord newPosition) override;
		void setOffset(Coord newOffset) override;
		void setSize(Coord newSize) override;
		void setAlignment(AlignmentHorizontal newHorizontal, AlignmentVertical newVertical) override;

	protected:
		Vector<Button*> buttons;
		Int columns = 1;
		Int rows = 3;
	};
}
#endif // WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_LIST_H
