#pragma once
#ifndef MOB_H
#define MOB_H
#include <string>

#include "Vob.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Mob : public Vob
	{
	protected:
		// Inheritance Ctor
		Mob(constexpr const char* className);
	public:
		Mob(String model);
		Mob(SQUserPointer ptr);

		// Properties
		Property<String> name;
		Property<Bool> focusOverride;

		// Read-only properties
		Property<String, true> scemeName;
	};
}
#endif
