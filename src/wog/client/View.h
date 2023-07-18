#ifndef WOG_CLIENT_VIEW_H
#define WOG_CLIENT_VIEW_H
#include "WogHeader.h"
#include "CustomTypes.h"
#include <GothicAPI/Gothic_II_Addon/API/zRndD3d.h>
#include <GothicAPI/Gothic_II_Addon/API/zview.h>

namespace wog
{
	class View : public zCView
	{
	public:
		View(int x, int y, int width, int height);

		void top();
		void setColor(int r, int g, int b);
		void setAlpha(int alpha);
		void setPosition(int x, int y);
		void setPositionPx(int x, int y);
		void setSize(int width, int height);
		void setSizePx(int width, int height);
		void setVisible(bool visible);
		void setFilename(const char* filename);

		g2o::Color getColor() const;
		int getAlpha() const;
		g2o::Position2d getPosition();
		g2o::Position2d getPositionPx();
		g2o::Size2d getSize();
		g2o::Size2d getSizePx();
		bool getVisible() const;
		const char* getFilename() const;

	protected:
		void Blit() override;
		void updateVertices();

		std::vector<zTRndSimpleVertex> vertices;
		zVEC2 position;
		zVEC2 size;
	};
}

#endif