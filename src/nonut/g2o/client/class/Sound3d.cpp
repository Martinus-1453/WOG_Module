#include "pch.h"
#include "Sound3d.h"
        
namespace nonut::g2o
{
	Sound3d::Sound3d(String fileName) :
		Class("Sound3d"),
		METHOD_CTOR(play),
		METHOD_CTOR(stop),
		METHOD_CTOR(isPlaying),
		//METHOD_CTOR(setTargetVob),
		METHOD_CTOR(setTargetPlayer),
		PROPERTY_CTOR(file),
		PROPERTY_CTOR(volume),
		PROPERTY_CTOR(looping),
		PROPERTY_CTOR(obstruction),
		PROPERTY_CTOR(radius),
		PROPERTY_CTOR(coneAngle),
		PROPERTY_CTOR(reverbLevel),
		PROPERTY_CTOR(ambient),
		PROPERTY_CTOR(pitchOffset),
		PROPERTY_CTOR(playingTime)
	{
		classCtor(fileName);
	}
}
