#pragma once
#ifndef MOB_H
#define MOB_H
#include <string>

#include "nonut/core/Vob.h"
#include "nonut/g2o/Shared/CustomTypes.h"

namespace nonut::g2o
{
	class Mob : public Vob
	{
	protected:
		// Inheritance Ctor
		Mob(constexpr const char* className);
	public:
		Mob(std::string model);
		Mob(SQUserPointer ptr);

		// Properties
		Property<std::string> name;
		Property<bool> focusOverride;

		// Read-only properties
		Property<std::string, true> scemeName;
	};
}
#endif
