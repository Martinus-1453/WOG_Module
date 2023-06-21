#ifndef WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_BUTTON_H
#define WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_BUTTON_H

#include <functional>

#include "Image.h"
#include "Label.h"
#include "gui/framework/Object.h"

namespace wog::gui
{
	class Button : public Object
	{
	public:
		Button();
		Button(const String& filename, const Coord& offset, const Coord& size);
		Button(const String& filename, const Rectangle& rect);
		Button(const Button& other);
		~Button() override;

		void update() override;
		void top() override;
		void setEnabled(bool value) override;
		void setVisible(bool value) override;
		void setPosition(Coord newPosition) override;
		void setOffset(Coord newOffset) override;
		void setSize(Coord newSize) override;

		void setButtons(const String& normal, const String& click, const String& hover);
		void setText(const String& text) const;

		void setAlignment(AlignmentHorizontal newHorizontal, AlignmentVertical newVertical) override;

		void setOnMouseClick(std::function<void(Int key)> lambda);
		void setOnMouseRelease(std::function<void(Int key)> lambda);
		void setOnMouseMove(std::function<void(Int key, Int x, Int y)> lambda);
		void setOnMouseHoverIn(std::function<void(Int x, Int y)> lambda);
		void setOnMouseHoverOut(std::function<void(Int x, Int y)> lambda);
		void setOnMouseWheel(std::function<void(Int z)> lambda);

	protected:
		void onMouseClick(Int key) const;
		void onMouseRelease(Int key) const;
		void onMouseMove(Int key, Int x, Int y) const;
		void onMouseHoverIn(Int x, Int y) const;
		void onMouseHoverOut(Int x, Int y) const;
		void onMouseWheel(Int z) const;

		Label* label;
		Image* image;

		String imageNormal;
		String imageClick;
		String imageHighlight;

		std::function<void(Int key)> onMouseClickLambda  = [](Int){};
		std::function<void(Int key)> onMouseReleaseLambda = [](Int) {};
		std::function<void(Int key, Int x, Int y)> onMouseMoveLambda = [](Int, Int, Int) {};
		std::function<void(Int x, Int y)> onMouseHoverInLambda = [](Int, Int) {};
		std::function<void(Int x, Int y)> onMouseHoverOutLambda = [](Int, Int) {};
		std::function<void(Int z)> onMouseWheelLambda = [](Int) {};
	};
}
#endif // WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_BUTTON_H
