#ifndef WOG_CLIENT_GUI_FRAMEWORK_OBJECT_H
#define WOG_CLIENT_GUI_FRAMEWORK_OBJECT_H
#include "CommonHeader.h"
#include <memory>

#include "util/Coord.h"
#include "util/Alignment.h"
#include "util/Rectangle.h"

namespace wog::gui
{
	class Object;
	using ObjectPtr = std::unique_ptr<Object>;

	class Object
	{
	public:
		Object() = default;
		virtual ~Object() = default;

		virtual void update();
		virtual void top();

		void attachToParent(Object* newParent);
		void detachFromParent();
		void attachChild(ObjectPtr&& child);
		void detachChild(Object* child);

		virtual void setEnabled(bool value);
		virtual void setVisible(bool value);
		[[nodiscard]] bool isEnabled() const;
		[[nodiscard]] bool isVisible() const;

		virtual void setCollision(bool value);
		[[nodiscard]] bool isCollidable() const;

		virtual void setPosition(Coord newPosition);
		[[nodiscard]] Coord getPosition() const;
		virtual void setOffset(Coord newOffset);
		virtual void setSize(Coord newSize);
		[[nodiscard]] Coord getSize() const;

		void setAligned(bool value);
		void setAlignment(AlignmentVertical newVertical);
		void setAlignment(AlignmentHorizontal newHorizontal);
		void setAlignment(AlignmentVertical newVertical, AlignmentHorizontal newHorizontal);
		virtual void setAlignment(AlignmentHorizontal newHorizontal, AlignmentVertical newVertical);
		std::pair<AlignmentVertical, AlignmentHorizontal> getAlignment();

		Object* getFirstCollision(Coord& mousePos);

		void updateOffset();
		void updateChildren() const;
		void updateAlignment();

	protected:
		Vector<ObjectPtr>::iterator getObjectPtrIterator(Vector<ObjectPtr>& vector) const;

		bool enabled = false;
		bool visible = false;
		bool needsUpdate = false;
		bool collision = true;
		bool aligned = true;

		AlignmentVertical vertical = AlignmentVertical::Top;
		AlignmentHorizontal horizontal = AlignmentHorizontal::Left;

		Rectangle rectangle{};
		Coord offset{};

		Object* parent{nullptr};
		Vector<ObjectPtr> children{};
	};
}
#endif // WOG_CLIENT_GUI_FRAMEWORK_OBJECT_H
