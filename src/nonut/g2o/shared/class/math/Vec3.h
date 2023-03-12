#ifndef NONUT_G2O_SHARED_CLASS_VEC3_H
#define NONUT_G2O_SHARED_CLASS_VEC3_H
#include "pch.h"
#include "Class.h"
#include "Stringify.h"

namespace nonut::g2o
{
	class Vec3 final : public Class, public Stringify<Vec3>
	{
	public:
		Vec3();
		Vec3(Float value);
		Vec3(Float x, Float y, Float z);
		Vec3(SQObject object);
		COPY_CTOR(Vec3);

		bool operator==(const Vec3& rhs) const;
		Vec3 operator+(const Vec3& rhs) const;
		Vec3 operator+(const Float& rhs) const;
		Vec3 operator-(const Vec3& rhs) const;
		Vec3 operator-(const Float& rhs) const;
		Vec3 operator*(const Vec3& rhs) const;
		Vec3 operator*(const Float& rhs) const;
		Vec3 operator/(const Vec3& rhs) const;
		Vec3 operator/(const Float& rhs) const;

		Vec3& operator+=(const Vec3& rhs);
		Vec3& operator-=(const Vec3& rhs);
		Vec3& operator*=(const Vec3& rhs);
		Vec3& operator/=(const Vec3& rhs);

		[[nodiscard]] String toString() const override;
		[[nodiscard]] auto toTuple() const
		{
			return std::make_tuple(x.get(), y.get(), z.get());
		}

		Property<Float> x;
		Property<Float> y;
		Property<Float> z;

		Function<Float> len;
		Function<Float> len2;
		Function<Float> lenApprox;
		Function<Float, Vec3> distance;
		Function<Vec3> normalize;
		Function<Vec3> normalizeSafe;
		Function<Vec3> normalizeApprox;

		Function<void, Float, Float, Float> set;
		Function<Bool, Vec3> isEqualEps;
		Function<Vec3> abs;
		Function<Vec3, Vec3> reflect;
		Function<void, Vec3, Vec3> swap;
		Function<Vec3, Vec3, Vec3> min;
		Function<Vec3, Vec3, Vec3> max;
		Function<Vec3, Vec3, Vec3> prod;
		Function<Float, Vec3, Vec3> dot;
		Function<Vec3, Vec3, Vec3> cross;
		Function<Vec3, Float, Vec3, Vec3> lerp;
	};
}
#endif // NONUT_G2O_SHARED_CLASS_VEC3_H
