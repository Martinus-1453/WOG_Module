#pragma once
#ifndef DAEDALUS_H
#define DAEDALUS_H
#include <string>

#include "nonut/core/Class.h"
#include "nonut/g2o/Shared/CustomTypes.h"

namespace nonut::g2o
{
	class Daedalus : public StaticClass
	{
	public:
		// TODO: Find a way to initialize static class Camera :)
		Daedalus();
		// HOPE WE WILL NEVER NEED THAT CLASS!
	};
}
#endif
