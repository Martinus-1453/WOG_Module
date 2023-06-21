#ifndef WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_SLOT_H_
#define WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_SLOT_H_

#include "Button.h"

namespace wog::gui
{
	class Slot : public Button
	{
	public:
		Slot();
		void setCollision(bool value) override;
		~Slot() override;
		void update() override;
		void top() override;
		void setEnabled(bool value) override;
		void setVisible(bool value) override;
		void setPosition(Coord newPosition) override;
		void setOffset(Coord newOffset) override;
		void setSize(Coord newSize) override;
		void setAlignment(AlignmentHorizontal newHorizontal, AlignmentVertical newVertical) override;

		void initSlot();
	protected:
		Image* icon{nullptr};
	};
}
#endif // WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_SLOT_H_