#pragma once
#ifndef DRAW_H
#define DRAW_H

#include <string>

#include "nonut/Class.h"
#include "nonut/Function.h"
#include "nonut/Property.h"

namespace nonut::g2o
{
	using namespace nonut;

	class Draw : public Class
	{
	public:
		Draw(int x, int y, std::string text);

		// Methods
		Function<void> top;
		//Function<void, int, int, int> setColor;
		////TODO: Make it work?
		////Function<{r,g,b}> getColor;
		//Function<void, float, float> setScale;
		////Function < {float, float} > getScale;
		//Function<void, int, int> setPosition;


		// Properties
		Property<bool> visible;
		//Property<std::string> text;
		//Property<std::string> font;
		//Property<int> alpha;
		//Property<float> rotation;

		//// Read-only properties
		//Property<int> width;
		//Property<int> widthPx;
		//Property<int> height;
		//Property<int> heightPx;
	};
}
#endif // DRAW_H
