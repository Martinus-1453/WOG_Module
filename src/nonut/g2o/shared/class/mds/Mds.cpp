#include "Mds.h"

namespace nonut::g2o
{
	Mds* Mds::get()
	{
		if (instance == nullptr)
		{
			instance = new Mds();
		}
		return instance;
	}

	Mds::Mds():
		StaticClass("Mds"),
		METHOD_CTOR(id),
		METHOD_CTOR(name)
	{
	}
}
