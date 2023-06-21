#include "Button.h"

#include <utility>

#include "function/SharedFunctions.h"
#include "gui/framework/EventHandler.h"

namespace wog::gui
{
	Button::Button() : Object()
	{
		auto imagePtr = std::make_unique<Image>();
		auto labelPtr = std::make_unique<Label>();

		label = labelPtr.get();
		label->setCollision(false);
		label->setAlignment(AlignmentVertical::Center);
		label->setAlignment(AlignmentHorizontal::Center);
		icon = imagePtr.get();
		icon->setAlignment(AlignmentVertical::Center);
		icon->setAlignment(AlignmentHorizontal::Center);
		icon->setCollision(false);

		attachChild(std::move(imagePtr));
		attachChild(std::move(labelPtr));

		EventHandler::get()->onMouseClickMap[this] = [this](const Int key)
			{ onMouseClick(key); };
		EventHandler::get()->onMouseReleaseMap[this] = [this](const Int key)
			{ onMouseRelease(key); };
		EventHandler::get()->onMouseMoveMap[this] = [this](const Int key, const Int x, const Int y)
			{onMouseMove(key, x, y); };
		EventHandler::get()->onMouseHooverInMap[this] = [this](const Int x, const Int y)
			{onMouseHoverIn(x, y); };
		EventHandler::get()->onMouseHooverOutMap[this] = [this](const Int x, const Int y)
			{onMouseHoverOut(x, y); };
		EventHandler::get()->onMouseWheelMap[this] = [this](const Int z)
			{onMouseWheel(z); };
	}

	Button::Button(const String& filename, const Coord& offset, const Coord& size) : Button()
	{
		Button::setOffset(offset);
		Button::setSize(size);
		icon->setFile(filename);
		icon->setSize(size);
		label->setText(filename);
	}

	Button::Button(const String& filename, const Rectangle& rect) : Button()
	{
		Button::setOffset(rect.position);
		Button::setSize(rect.size);
		icon->setOffset(rect.position);
		icon->setSize(rect.size);
		icon->setFile(filename);
		label->setText(filename);
	}

	Button::Button(const Button& other) : Button()
	{
		imageNormal = other.imageNormal;
		imageClick = other.imageClick;
		imageHighlight = other.imageHighlight;

		onMouseClickLambda = other.onMouseClickLambda;
		onMouseHoverInLambda = other.onMouseHoverInLambda;
		onMouseHoverOutLambda = other.onMouseHoverOutLambda;
		onMouseMoveLambda = other.onMouseMoveLambda;
		onMouseReleaseLambda = other.onMouseReleaseLambda;
		onMouseWheelLambda = other.onMouseWheelLambda;

		Button::setSize(other.getSize());
		Button::setPosition(other.getPosition());
	}

	Button::~Button()
	{
		detachChild(label);
		detachChild(icon);
	}

	void Button::update()
	{
		Object::update();
	}

	void Button::top()
	{
		icon->top();
		label->top();

		Object::top();
	}

	void Button::setEnabled(const bool value)
	{
		Object::setEnabled(value);
	}

	void Button::setVisible(const bool value)
	{
		Object::setVisible(value);
	}

	void Button::setPosition(const Coord newPosition)
	{
		Object::setPosition(newPosition);
	}

	void Button::setOffset(const Coord newOffset)
	{
		Object::setOffset(newOffset);
	}

	void Button::setSize(const Coord newSize)
	{
		icon->setSize(newSize);
		Object::setSize(newSize);
	}

	void Button::setButtons(const String& normal, const String& click, const String& hover)
	{
		imageNormal = normal;
		imageClick = click;
		imageHighlight = hover;

		icon->setFile(normal);
	}

	void Button::setText(const String& text) const
	{
		label->setText(text);
	}

	void Button::setAlignment(const AlignmentHorizontal newHorizontal, const AlignmentVertical newVertical)
	{
		label->setAlignment(AlignmentHorizontal::Center);
		icon->setAlignment(AlignmentHorizontal::Center);
		label->setAlignment(AlignmentVertical::Center);
		icon->setAlignment(AlignmentVertical::Center);
		Object::setAlignment(newHorizontal, newVertical);
	}

	void Button::setOnMouseClick(std::function<void(Int key)> lambda)
	{
		onMouseClickLambda = std::move(lambda);
	}

	void Button::setOnMouseRelease(std::function<void(Int key)> lambda)
	{
		onMouseReleaseLambda = std::move(lambda);
	}

	void Button::setOnMouseMove(std::function<void(Int key, Int x, Int y)> lambda)
	{
		onMouseMoveLambda = std::move(lambda);
	}

	void Button::setOnMouseHoverIn(std::function<void(Int x, Int y)> lambda)
	{
		onMouseHoverInLambda = std::move(lambda);
	}

	void Button::setOnMouseHoverOut(std::function<void(Int x, Int y)> lambda)
	{
		onMouseHoverOutLambda = std::move(lambda);
	}

	void Button::setOnMouseWheel(std::function<void(Int z)> lambda)
	{
		onMouseWheelLambda = std::move(lambda);
	}

	void Button::onMouseClick(const Int key) const
	{
		icon->setFile(imageClick);
		onMouseClickLambda(key);
	}

	void Button::onMouseRelease(const Int key) const
	{
		icon->setFile(imageNormal);
		onMouseReleaseLambda(key);
	}

	void Button::onMouseMove(const Int key,const Int x, const Int y) const
	{
		onMouseMoveLambda(key, x, y);
	}

	void Button::onMouseHoverIn(const Int x, const Int y) const
	{
		icon->setFile(imageHighlight);
		onMouseHoverInLambda(x, y);
	}

	void Button::onMouseHoverOut(const Int x, const Int y) const
	{
		icon->setFile(imageNormal);
		onMouseHoverOutLambda(x, y);
	}

	void Button::onMouseWheel(const Int z) const
	{
		onMouseWheelLambda(z);
	}
}
