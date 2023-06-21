#ifndef WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_IMAGE_H
#define WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_IMAGE_H
#include "class/ui/Texture.h"
#include "gui/framework/Object.h"

namespace wog::gui
{
	class Image : public Object
	{
	public:
		Image();
		Image(const String& filename, Coord position, Coord size);
		Image(const String& filename, Rectangle rect);

		void update() override;
		void top() override;
		void setEnabled(bool value) override;
		void setVisible(bool value) override;
		void setPosition(Coord newPosition) override;
		void setOffset(Coord newOffset) override;
		void setSize(Coord newSize) override;

		[[nodiscard]] String getFile() const;
		void setFile(const String& file);

		[[nodiscard]] g2o::Color getColor() const;
		void setColor(g2o::Color color);
		void setColor(Int r, Int g, Int b);

		[[nodiscard]] Int getAlpha() const;
		void setAlpha(Int alpha);

		[[nodiscard]] Rectangle getViewport() const;
		void setViewport(const Rectangle& rect) const;
		void setViewport(const Coord& position, const Coord& size) const;

	protected:
		std::unique_ptr<g2o::Texture> image;
	};
}
#endif // WOG_CLIENT_GUI_FRAMEWORK_COMPONENT_IMAGE_H
