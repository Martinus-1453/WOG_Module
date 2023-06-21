#include "Equipment.h"

#include "Slot.h"

namespace wog::gui
{
	Equipment::Equipment() : List()
	{
	}

	Equipment::Equipment(Int x, Int y, const Coord& elementSize) : Equipment()
	{
		buttons = Vector<Button*>(columns * rows, nullptr);
		this->columns = columns;
		this->rows = rows;

		int i = 0;
		int j = 0;

		auto [w, h] = elementSize.getPx();

		for (auto&& buttonPtr : buttons)
		{
			auto button = std::make_unique<Slot>();
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
		auto slot1 = dynamic_cast<Slot*>(buttons[0]);

		List::setSize(Coord{ columns * w, rows * h });
	}
}
