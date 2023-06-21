#include "List.h"

namespace wog::gui
{
	List::List() : Object()
	{
	}

	List::List(const Int columns, const Int rows, const Coord& elementSize) : List()
	{
		buttons = Vector<Button*>(columns * rows, nullptr);
		this->columns = columns;
		this->rows = rows;

		int i = 0;
		int j = 0;

		auto [w, h] = elementSize.getPx();

		for (auto && buttonPtr : buttons)
		{
			auto button = std::make_unique<Button>();
			buttonPtr = button.get();
			buttonPtr->setAligned(false);
			attachChild(std::move(button));
			buttonPtr->setSize(elementSize);
			buttonPtr->setButtons("Inv_Slot", "Inv_Slot_Highlighted_Focus", "Inv_Slot_Focus");
			
			buttonPtr->setPosition(Coord(i * w, j * h));
			buttonPtr->setText(std::to_string(i) + " " + std::to_string(j));
			i = (i + 1) % columns;
			if (i == 0) ++j;
		}
		List::setSize(Coord{ columns * w, rows * h});
	}

	void List::update()
	{
		Object::update();
	}

	void List::top()
	{
		Object::top();
	}

	void List::setEnabled(const bool value)
	{
		Object::setEnabled(value);
	}

	void List::setVisible(const bool value)
	{
		Object::setVisible(value);
	}

	void List::setCollision(const bool value)
	{
		Object::setCollision(value);
	}

	void List::setPosition(const Coord newPosition)
	{
		Object::setPosition(newPosition);

		int i = 0;
		int j = 0;

		for (auto&& buttonPtr : buttons)
		{
			auto [w, h] = buttonPtr->getSize().getPx();
			buttonPtr->setPosition(Coord(i * w, j * h));
			buttonPtr->setText(std::to_string(i) + " " + std::to_string(j));
			i = (i + 1) % columns;
			if (i == 0) ++j;
		}
	}

	void List::setOffset(const Coord newOffset)
	{
		Object::setOffset(newOffset);
	}

	void List::setSize(const Coord newSize)
	{
		Object::setSize(newSize);
	}

	void List::setAlignment(const AlignmentHorizontal newHorizontal, const AlignmentVertical newVertical)
	{
		Object::setAlignment(newHorizontal, newVertical);
	}
}
