#include "Label.h"

namespace wog::gui
{
	Label::Label() : Object()
	{
		textObject = std::make_unique<g2o::Draw>(0, 0, "");
	}

	Label::Label(const String& text) : Label()
	{
		setText(text);
	}

	void Label::update()
	{
		Object::update();
	}

	void Label::top()
	{
		textObject->top();
		Object::top();
	}

	void Label::setEnabled(const bool value)
	{
		Object::setEnabled(value);
	}

	void Label::setVisible(const bool value)
	{
		textObject->visible = value;
		Object::setVisible(value);
	}

	void Label::setSize(const Coord newSize)
	{
		Object::setSize(newSize);
	}

	void Label::setPosition(const Coord newPosition)
	{
		Object::setPosition(newPosition);
		std::apply(textObject->setPositionPx, getPosition().getPx());
	}

	void Label::setOffset(const Coord newOffset)
	{
		Object::setOffset(newOffset);
		std::apply(textObject->setPositionPx, getPosition().getPx());
	}

	String Label::getText() const
	{
		return textObject->text;
	}

	void Label::setText(const String& text)
	{
		textObject->text = text;
		rectangle.size = Coord(textObject->widthPx, textObject->heightPx);
	}

	String Label::getFont() const
	{
		return textObject->font;
	}

	void Label::setFont(const String& font)
	{
		textObject->font = font;
		rectangle.size = Coord(textObject->widthPx, textObject->heightPx);
	}

	g2o::Color Label::getColor() const
	{
		return textObject->getColor();
	}

	void Label::setColor(g2o::Color color)
	{
		std::apply(textObject->setColor, color.toTuple());
	}

	void Label::setColor(const Int r, const Int g, const Int b)
	{
		textObject->setColor(r, g, b);
	}

	Int Label::getAlpha() const
	{
		return textObject->alpha;
	}

	void Label::setAlpha(const Int alpha)
	{
		textObject->alpha = alpha;
	}
}
