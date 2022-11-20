#pragma once
#ifndef TIMESTEP_H
#define TIMESTEP_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Timestep : public Class
	{
	public:
		// TODO: CHECK IF THIS WORKS THIS WAY!
		Timestep();

		// Methods
		Function<void> reset;
		Function<void, float> update;

		// Properties
		Property<float> factorMotion;

		// Read-only properties
		Property<float, true> frameTime;
		Property<float, true> totalTime;
		Property<float, true> frameTimeSecs;
		Property<float, true> totalTimeSecs;
	};
}
#endif
