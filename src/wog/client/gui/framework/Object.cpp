#include "Object.h"

#include <ranges>

namespace wog::gui
{
	void Object::update()
	{
		for (auto&& child : children)
		{
			child->update();
		}
		needsUpdate = false;
	}

	void Object::top()
	{
		for (auto&& child : children)
		{
			child->top();
		}
	}

	void Object::attachToParent(Object* newParent)
	{
		const auto childPtr = getObjectPtrIterator(parent->children);
		newParent->children.push_back(std::move(*childPtr));
		parent->children.erase(childPtr);
		parent = newParent;
	}

	void Object::detachFromParent()
	{
		const auto childPtr = getObjectPtrIterator(parent->children);
		parent->children.erase(childPtr);
		parent = nullptr;
	}

	void Object::attachChild(ObjectPtr&& child)
	{
		const auto childPtr = child.get();
		children.emplace_back(std::move(child));
		childPtr->parent = this;
		childPtr->updateOffset();
		childPtr->updateAlignment();
		updateChildren();
	}

	void Object::detachChild(Object* child)
	{
		const auto childPtr = getObjectPtrIterator(parent->children);
		children.erase(childPtr);
	}

	void Object::setEnabled(const bool value)
	{
		enabled = value;
		for (auto&& child : children)
		{
			child->setEnabled(value);
		}
	}

	void Object::setVisible(const bool value)
	{
		visible = value;
		for (auto&& child : children)
		{
			child->setVisible(value);
		}
	}

	bool Object::isEnabled() const
	{
		return enabled;
	}

	bool Object::isVisible() const
	{
		return visible;
	}

	void Object::setCollision(const bool value)
	{
		collision = value;
	}

	bool Object::isCollidable() const
	{
		return collision;
	}

	void Object::setPosition(const Coord newPosition)
	{
		rectangle.position = parent != nullptr ? newPosition + parent->getPosition() : newPosition;

		updateOffset();
		updateAlignment();
		updateChildren();
	}

	Coord Object::getPosition() const
	{
		return rectangle.position;
	}

	void Object::setOffset(const Coord newOffset)
	{
		offset = newOffset;
		setPosition(offset);
		updateChildren();
	}

	void Object::setSize(const Coord newSize)
	{
		rectangle.size = newSize;
		updateAlignment();
		setPosition(offset);
		updateChildren();
	}

	Coord Object::getSize() const
	{
		return rectangle.size;
	}

	void Object::setAligned(const bool value)
	{
		aligned = value;
	}

	void Object::setAlignment(const AlignmentVertical newVertical)
	{
		setAlignment(horizontal, newVertical);
	}

	void Object::setAlignment(const AlignmentHorizontal newHorizontal)
	{
		setAlignment(newHorizontal, vertical);
	}

	void Object::setAlignment(const AlignmentVertical newVertical, const AlignmentHorizontal newHorizontal)
	{
		setAlignment(newHorizontal, newVertical);
	}

	void Object::setAlignment(const AlignmentHorizontal newHorizontal, const AlignmentVertical newVertical)
	{
		horizontal = newHorizontal;
		vertical = newVertical;
		updateAlignment();
		setOffset(offset);
	}

	std::pair<AlignmentVertical, AlignmentHorizontal> Object::getAlignment()
	{
		return std::make_pair(vertical, horizontal);
	}

	Object* Object::getFirstCollision(Coord& mousePos)
	{
		Object* result = nullptr;

		auto isObjectOk = [](const Object* object, const Coord& pos)
		{
			return object->isEnabled() && object->isCollidable() && object->rectangle.collide(pos);
		};

		for (auto&& object : std::views::reverse(children))
		{
			if (isObjectOk(object.get(), mousePos))
			{
				result = object->getFirstCollision(mousePos);
				break;
			}
		}

		if (result == nullptr)
		{
			result = isObjectOk(this, mousePos) ? this : nullptr;
		}

		return result;
	}

	void Object::updateOffset()
	{
		if (parent != nullptr)
		{
			offset = getPosition() - parent->getPosition();
		}
	}

	void Object::updateChildren() const
	{
		for (auto&& child : children)
		{
			child->updateOffset();
			child->updateAlignment();
			child->setPosition(child->offset);
			child->updateChildren();
		}
	}

	void Object::updateAlignment()
	{
		if (parent == nullptr) return;
		if (!aligned) return;

		auto [w, h] = getSize().getPx();
		auto [wParent, hParent] = parent->getSize().getPx();

		switch (horizontal)
		{
		case AlignmentHorizontal::Left:
			w = 0;
			break;
		case AlignmentHorizontal::Center:
			w = abs(wParent - w) / 2;
			break;
		case AlignmentHorizontal::Right:
			w = abs(wParent - w);
			break;
		}

		switch (vertical)
		{
		case AlignmentVertical::Top:
			h = 0;
			break;
		case AlignmentVertical::Center:
			h = abs(hParent - h) / 2;
			break;
		case AlignmentVertical::Bottom:
			h = abs(hParent - h);
			break;
		}

		offset = Coord{w, h};
	}

	Vector<ObjectPtr>::iterator Object::getObjectPtrIterator(Vector<ObjectPtr>& vector) const
	{
		return std::ranges::find_if(vector, [&](const ObjectPtr& p)
		{
			return p.get() == this;
		});
	}
}
