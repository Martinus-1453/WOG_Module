#pragma once
#ifndef SKY_H
#define SKY_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Sky : public StaticClass
	{
	public:
		// TODO: ctor for statics
		Sky();

		// Methods
		Function<void, int, int> setRainStartTime;
		Function<TimeHM> getRainStartTime;
		Function<void, int, int> setRainStopTime;
		Function<TimeHM> getRainStopTime;
		Function<void, int, int, int> setFogColor;
		Function<void, int, int, int> setCloudsColor;
		Function<void, int, int> setPlanterSize;
		Function<void, int, int, int, int, int> setPlanetColor;
		Function<void, int, int, int> setLightingColor;

		// Properties
		Property<int> weather;
		Property<bool> raining;
		Property<bool> renderLightning;
		Property<float> windScale;
		Property<float> weatherWeight;
		Property<bool> dontRain;
		Property<bool> darkSky;
	};
}
#endif
