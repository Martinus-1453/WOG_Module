#include "Vec3.h"

namespace nonut::g2o
{
	Vec3::Vec3() : Vec3(SQ_NULL)
	{
		classCtor();
	}

	Vec3::Vec3(Float value) : Vec3(SQ_NULL)
	{
		classCtor(value);
	}

	Vec3::Vec3(Float x, Float y, Float z) : Vec3(SQ_NULL)
	{
		classCtor(x, y, z);
	}

	Vec3::Vec3(SQObject object) :
		Class("Vec3", object),
		PROPERTY_CTOR(x),
		PROPERTY_CTOR(y),
		PROPERTY_CTOR(z),
		METHOD_CTOR(len),
		METHOD_CTOR(len2),
		METHOD_CTOR(lenApprox),
		METHOD_CTOR(distance),
		METHOD_CTOR(normalize),
		METHOD_CTOR(normalizeSafe),
		METHOD_CTOR(normalizeApprox),
		METHOD_CTOR(set),
		METHOD_CTOR(isEqualEps),
		METHOD_CTOR(abs),
		METHOD_CTOR(reflect),
		METHOD_CTOR(swap),
		METHOD_CTOR(min),
		METHOD_CTOR(max),
		METHOD_CTOR(prod),
		METHOD_CTOR(dot),
		METHOD_CTOR(cross),
		METHOD_CTOR(lerp)
	{
	}

	bool Vec3::operator==(const Vec3& rhs) const
	{
		return this->x.get() == rhs.x.get() &&
			this->y.get() == rhs.y.get() &&
			this->z.get() == rhs.z.get();
	}

	Vec3 Vec3::operator+(const Vec3& rhs) const
	{
		return {
			this->x.get() + rhs.x.get(),
			this->y.get() + rhs.y.get(),
			this->z.get() + rhs.z.get()
		};
	}

	Vec3 Vec3::operator+(const Float& rhs) const
	{
		return {
			this->x.get() + rhs,
			this->y.get() + rhs,
			this->z.get() + rhs
		};
	}

	Vec3 Vec3::operator-(const Vec3& rhs) const
	{
		return {
			this->x.get() - rhs.x.get(),
			this->y.get() - rhs.y.get(),
			this->z.get() - rhs.z.get()
		};
	}

	Vec3 Vec3::operator-(const Float& rhs) const
	{
		return {
			this->x.get() - rhs,
			this->y.get() - rhs,
			this->z.get() - rhs
		};
	}

	Vec3 Vec3::operator*(const Vec3& rhs) const
	{
		return {
			this->x.get() * rhs.x.get(),
			this->y.get() * rhs.y.get(),
			this->z.get() * rhs.z.get()
		};
	}

	Vec3 Vec3::operator*(const Float& rhs) const
	{
		return {
			this->x.get() * rhs,
			this->y.get() * rhs,
			this->z.get() * rhs
		};
	}

	Vec3 Vec3::operator/(const Vec3& rhs) const
	{
		return {
			this->x.get() / rhs.x.get(),
			this->y.get() / rhs.y.get(),
			this->z.get() / rhs.z.get()
		};
	}

	Vec3 Vec3::operator/(const Float& rhs) const
	{
		return {
			this->x.get() / rhs,
			this->y.get() / rhs,
			this->z.get() / rhs
		};
	}

	Vec3& Vec3::operator+=(const Vec3& rhs)
	{
		this->x = this->x.get() + rhs.x.get();
		this->y = this->y.get() + rhs.y.get();
		this->z = this->z.get() + rhs.z.get();
		return *this;
	}

	Vec3& Vec3::operator-=(const Vec3& rhs)
	{
		this->x = this->x.get() - rhs.x.get();
		this->y = this->y.get() - rhs.y.get();
		this->z = this->z.get() - rhs.z.get();
		return *this;
	}

	Vec3& Vec3::operator*=(const Vec3& rhs)
	{
		this->x = this->x.get() * rhs.x.get();
		this->y = this->y.get() * rhs.y.get();
		this->z = this->z.get() * rhs.z.get();
		return *this;
	}

	Vec3& Vec3::operator/=(const Vec3& rhs)
	{
		this->x = this->x.get() / rhs.x.get();
		this->y = this->y.get() / rhs.y.get();
		this->z = this->z.get() / rhs.z.get();
		return *this;
	}

	String Vec3::toString() const
	{
		return
			'[' +
			std::to_string(this->x.get()) +
			", " +
			std::to_string(this->y.get()) +
			", " +
			std::to_string(this->z.get()) +
			']';
	}
}
