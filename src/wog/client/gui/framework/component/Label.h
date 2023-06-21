#ifndef WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_LABEL_H
#define WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_LABEL_H
#include "class/ui/Draw.h"
#include "gui/framework/Object.h"

namespace wog::gui
{
	class Label : public Object
	{
	public:
		Label();
		explicit Label(const String& text);
		~Label() override = default;
		void update() override;
		void top() override;
		void setEnabled(bool value) override;
		void setVisible(bool value) override;
		void setSize(Coord newSize) override;
		void setPosition(Coord newPosition) override;
		void setOffset(Coord newOffset) override;

		String getText() const;
		void setText(const String& text);

		String getFont() const;
		void setFont(const String& font);

		g2o::Color getColor() const;
		void setColor(g2o::Color color);
		void setColor(Int r, Int g, Int b);

		Int getAlpha() const;
		void setAlpha(Int alpha);

	protected:
		std::unique_ptr<g2o::Draw> textObject;
	};
}
#endif // WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_LABEL_H
