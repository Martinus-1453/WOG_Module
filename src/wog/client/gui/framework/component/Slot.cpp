#include "Slot.h"

namespace wog::gui
{
	Slot::Slot() : Button()
	{
		auto iconPtr = std::make_unique<Image>();

		icon = iconPtr.get();
		icon->setAlignment(AlignmentVertical::Center);
		icon->setAlignment(AlignmentHorizontal::Center);
		icon->setCollision(false);

		attachChild(std::move(iconPtr));
	}

	void Slot::setCollision(bool value)
	{
		Button::setCollision(value);
	}

	Slot::~Slot()
	{
		detachChild(icon);
	}

	void Slot::update()
	{
		Button::update();
	}

	void Slot::top()
	{
		icon->top();
		Button::top();
	}

	void Slot::setEnabled(bool value)
	{
		Button::setEnabled(value);
	}

	void Slot::setVisible(bool value)
	{
		Button::setVisible(value);
	}

	void Slot::setPosition(Coord newPosition)
	{
		Button::setPosition(newPosition);
	}

	void Slot::setOffset(Coord newOffset)
	{
		Button::setOffset(newOffset);
	}

	void Slot::setSize(Coord newSize)
	{
		Button::setSize(newSize);
	}

	void Slot::setAlignment(AlignmentHorizontal newHorizontal, AlignmentVertical newVertical)
	{
		Button::setAlignment(newHorizontal, newVertical);
	}
}
