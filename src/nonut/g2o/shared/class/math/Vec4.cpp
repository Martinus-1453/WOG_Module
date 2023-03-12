#include "Vec4.h"

namespace nonut::g2o
{
	Vec4::Vec4() : Vec4(SQ_NULL)
	{
		classCtor();
	}

	Vec4::Vec4(Float value) : Vec4(SQ_NULL)
	{
		classCtor(value);
	}

	Vec4::Vec4(Float x, Float y, Float z, Float w) : Vec4(SQ_NULL)
	{
		classCtor(x, y, z, w);
	}

	Vec4::Vec4(SQObject object) :
		Class("Vec4", object),
		PROPERTY_CTOR(x),
		PROPERTY_CTOR(y),
		PROPERTY_CTOR(z),
		PROPERTY_CTOR(w),
		METHOD_CTOR(len),
		METHOD_CTOR(len2),
		METHOD_CTOR(lenApprox),
		METHOD_CTOR(normalize),
		METHOD_CTOR(normalizeSafe),
		METHOD_CTOR(normalizeApprox),
		METHOD_CTOR(set),
		METHOD_CTOR(isEqualEps),
		METHOD_CTOR(abs),
		METHOD_CTOR(swap),
		METHOD_CTOR(min),
		METHOD_CTOR(max),
		METHOD_CTOR(prod),
		METHOD_CTOR(dot),
		METHOD_CTOR(lerp)
	{
	}

	bool Vec4::operator==(const Vec4& rhs) const
	{
		return this->x.get() == rhs.x.get() &&
			this->y.get() == rhs.y.get() &&
			this->z.get() == rhs.z.get() &&
			this->w.get() == rhs.w.get();
	}

	Vec4 Vec4::operator+(const Vec4& rhs) const
	{
		return {
			this->x.get() + rhs.x.get(),
			this->y.get() + rhs.y.get(),
			this->z.get() + rhs.z.get(),
			this->w.get() + rhs.w.get()
		};
	}

	Vec4 Vec4::operator+(const Float& rhs) const
	{
		return {
			this->x.get() + rhs,
			this->y.get() + rhs,
			this->z.get() + rhs,
			this->w.get() + rhs
		};
	}

	Vec4 Vec4::operator-(const Vec4& rhs) const
	{
		return {
			this->x.get() - rhs.x.get(),
			this->y.get() - rhs.y.get(),
			this->z.get() - rhs.z.get(),
			this->w.get() - rhs.w.get()
		};
	}

	Vec4 Vec4::operator-(const Float& rhs) const
	{
		return {
			this->x.get() - rhs,
			this->y.get() - rhs,
			this->z.get() - rhs,
			this->w.get() - rhs
		};
	}

	Vec4 Vec4::operator*(const Vec4& rhs) const
	{
		return {
			this->x.get() * rhs.x.get(),
			this->y.get() * rhs.y.get(),
			this->z.get() * rhs.z.get(),
			this->w.get() * rhs.w.get()
		};
	}

	Vec4 Vec4::operator*(const Float& rhs) const
	{
		return {
			this->x.get() * rhs,
			this->y.get() * rhs,
			this->z.get() * rhs,
			this->w.get() * rhs
		};
	}

	Vec4 Vec4::operator/(const Vec4& rhs) const
	{
		return {
			this->x.get() / rhs.x.get(),
			this->y.get() / rhs.y.get(),
			this->z.get() / rhs.z.get(),
			this->w.get() / rhs.w.get()
		};
	}

	Vec4 Vec4::operator/(const Float& rhs) const
	{
		return {
			this->x.get() / rhs,
			this->y.get() / rhs,
			this->z.get() / rhs,
			this->w.get() / rhs
		};
	}

	Vec4& Vec4::operator+=(const Vec4& rhs)
	{
		this->x = this->x.get() + rhs.x.get();
		this->y = this->y.get() + rhs.y.get();
		this->z = this->z.get() + rhs.z.get();
		this->w = this->w.get() + rhs.w.get();
		return *this;
	}

	Vec4& Vec4::operator-=(const Vec4& rhs)
	{
		this->x = this->x.get() - rhs.x.get();
		this->y = this->y.get() - rhs.y.get();
		this->z = this->z.get() - rhs.z.get();
		this->w = this->w.get() - rhs.w.get();
		return *this;
	}

	Vec4& Vec4::operator*=(const Vec4& rhs)
	{
		this->x = this->x.get() * rhs.x.get();
		this->y = this->y.get() * rhs.y.get();
		this->z = this->z.get() * rhs.z.get();
		this->w = this->w.get() * rhs.w.get();
		return *this;
	}

	Vec4& Vec4::operator/=(const Vec4& rhs)
	{
		this->x = this->x.get() / rhs.x.get();
		this->y = this->y.get() / rhs.y.get();
		this->z = this->z.get() / rhs.z.get();
		this->w = this->w.get() / rhs.w.get();
		return *this;
	}
}