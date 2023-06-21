#include "Image.h"

namespace wog::gui
{
	Image::Image() : Object()
	{
		image = std::make_unique<g2o::Texture>(0,0,0,0, "none");
	}

	Image::Image(const String& filename, const Coord position, const Coord size) : Image()
	{
		Image::setOffset(position);
		Image::setSize(size);
		setFile(filename);
	}

	Image::Image(const String& filename, const Rectangle rect) : Image()
	{
		Image::setOffset(rect.position);
		Image::setSize(rect.size);
		setFile(filename);
	}

	void Image::update()
	{
		Object::update();
	}

	void Image::top()
	{
		Object::top();
	}

	void Image::setEnabled(const bool value)
	{
		Object::setEnabled(value);
	}

	void Image::setVisible(const bool value)
	{
		image->visible = value;
		Object::setVisible(value);
	}

	void Image::setPosition(const Coord newPosition)
	{
		Object::setPosition(newPosition);
		std::apply(image->setPositionPx, getPosition().getPx());
	}

	void Image::setOffset(const Coord newOffset)
	{
		Object::setOffset(newOffset);
		std::apply(image->setPositionPx, getPosition().getPx());
	}

	void Image::setSize(const Coord newSize)
	{
		Object::setSize(newSize);
		std::apply(image->setSizePx, getSize().getPx());
	}

	String Image::getFile() const
	{
		return image->file;
	}

	void Image::setFile(const String& file)
	{
		image->file = file;
	}

	g2o::Color Image::getColor() const
	{
		return image->getColor();
	}

	void Image::setColor(g2o::Color color)
	{
		std::apply(image->setColor, color.toTuple());
	}

	void Image::setColor(const Int r, const Int g, const Int b)
	{
		image->setColor(r, g, b);
	}

	Int Image::getAlpha() const
	{
		return image->alpha;
	}

	void Image::setAlpha(const Int alpha)
	{
		image->alpha = alpha;
	}

	Rectangle Image::getViewport() const
	{
		auto [x, y, width, height] = image->getRectPx().toTuple();
		return Rectangle{
			Coord{x, y},
			Coord{width, height}
		};
	}

	void Image::setViewport(const Rectangle& rect) const
	{
		auto [x, y] = getPosition().getPx();
		auto [width, height] = getSize().getPx();
		image->setRectPx(x, y, width, height);
	}

	void Image::setViewport(const Coord& position, const Coord& size) const
	{
		auto [x, y] = position.getPx();
		auto [width, height] = size.getPx();
		image->setRectPx(x, y, width, height);
	}
}
