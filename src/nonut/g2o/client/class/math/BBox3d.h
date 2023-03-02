#ifndef NONUT_G2O_CLIENT_CLASS_BBOX3D_H
#define NONUT_G2O_CLIENT_CLASS_BBOX3D_H

#include "pch.h"
#include "Class.h"
#include "class/math/Vec3.h"

namespace nonut::g2o
{
	class BBox3d : public Class
	{
	public:
		BBox3d(SQObject object);
		COPY_CTOR(BBox3d);

		Property<Vec3> mins;
		Property<Vec3> maxs;
		Property<Vec3, true> center;

		Function<Bool, BBox3d> intersecting;
	};
}
#endif //NONUT_G2O_CLIENT_CLASS_BBOX3D_H