#ifndef WOG_CLIENT_GUI_SCENES_INVENTORYSCENE_H_
#define WOG_CLIENT_GUI_SCENES_INVENTORYSCENE_H_
#include "gui/framework/Scene.h"
#include "gui/framework/SceneManager.h"
#include "gui/SceneEnum.h"
#include "gui/framework/component/Button.h"
#include "gui/framework/component/Image.h"
#include "gui/framework/component/List.h"

namespace wog::gui
{
	inline void createInventoryGui()
	{
		SceneManager::scenes[Inventory] = Scene{};
		auto&& invRoot = SceneManager::scenes[Inventory].root;

		auto background = 
			std::make_unique<Image>("LETTERS", Coord{ 0,0 }, Coord{ 250,250 });
		const auto backgroundPtr = background.get();

		invRoot->attachChild(std::move(background));

		auto list = 
			std::make_unique<List>(6,6, Coord{75,75});

		const auto listPtr = list.get();
		backgroundPtr->attachChild(std::move(list));
		backgroundPtr->setAligned(false);
		backgroundPtr->setSize(Coord{ 500, 500 });
		backgroundPtr->setPosition(Coord{ 200, 200 });

		listPtr->setAlignment(AlignmentHorizontal::Center, AlignmentVertical::Center);

		invRoot->setVisible(true);
		invRoot->setEnabled(true);

		C_F->setCursorVisible(true);
	}
}
#endif // WOG_CLIENT_GUI_SCENES_INVENTORYSCENE_H_