#ifndef NONUT_G2O_SHARED_CLASS_VEC4_H
#define NONUT_G2O_SHARED_CLASS_VEC4_H
#include "pch.h"
#include "Class.h"

namespace nonut::g2o
{
	class Vec4 : public Class
	{
	public:
		Vec4();
		Vec4(Float value);
		Vec4(Float x, Float y, Float z, Float w);
		Vec4(SQObject object);
		COPY_CTOR(Vec4);

		bool operator==(const Vec4& rhs) const;
		Vec4 operator+(const Vec4& rhs) const;
		Vec4 operator+(const Float& rhs) const;
		Vec4 operator-(const Vec4& rhs) const;
		Vec4 operator-(const Float& rhs) const;
		Vec4 operator*(const Vec4& rhs) const;
		Vec4 operator*(const Float& rhs) const;
		Vec4 operator/(const Vec4& rhs) const;
		Vec4 operator/(const Float& rhs) const;

		Vec4& operator+=(const Vec4& rhs);
		Vec4& operator-=(const Vec4& rhs);
		Vec4& operator*=(const Vec4& rhs);
		Vec4& operator/=(const Vec4& rhs);

		Property<Float> x;
		Property<Float> y;
		Property<Float> z;
		Property<Float> w;

		Function<Float> len;
		Function<Float> len2;
		Function<Float> lenApprox;
		Function<Vec4> normalize;
		Function<Vec4> normalizeSafe;
		Function<Vec4> normalizeApprox;

		Function<void, Float, Float, Float> set;
		Function<Bool, Vec4> isEqualEps;
		Function<Vec4> abs;
		// static methods
		Function<void, Vec4, Vec4> swap;
		Function<Vec4, Vec4, Vec4> min;
		Function<Vec4, Vec4, Vec4> max;
		Function<Vec4, Vec4, Vec4> prod;
		Function<Float, Vec4, Vec4> dot;
		Function<Vec4, Float, Vec4, Vec4> lerp;
	};
}
#endif // NONUT_G2O_SHARED_CLASS_VEC4_H
