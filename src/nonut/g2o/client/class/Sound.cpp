#include "pch.h"
#include "Sound.h"
        
namespace nonut::g2o
{
	Sound::Sound(std::string fileName) :
		Class("Sound"),
		METHOD_CTOR(play),
		METHOD_CTOR(stop),
		METHOD_CTOR(isPlaying),
		PROPERTY_CTOR(file),
		PROPERTY_CTOR(volume),
		PROPERTY_CTOR(looping),
		PROPERTY_CTOR(balance),
		PROPERTY_CTOR(playingTime)
	{
		classCtor(fileName);
	}
}
