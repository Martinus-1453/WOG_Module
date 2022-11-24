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
		Function<void, Float> update;

		// Properties
		Property<Float> factorMotion;

		// Read-only properties
		Property<Float, true> frameTime;
		Property<Float, true> totalTime;
		Property<Float, true> frameTimeSecs;
		Property<Float, true> totalTimeSecs;
	};
}
#endif
