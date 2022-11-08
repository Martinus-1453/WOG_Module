#pragma once
#ifndef CLASS_H
#define CLASS_H
#include "pch.h"
#include <string>

// Forward declaration

namespace nonut {

	static constexpr auto CONSTRUCTOR_NAME = "constructor";

	class Class
	{
	public:
		Class(std::string className);
		~Class();

	protected:
		// Object holding information about class
		HSQOBJECT classObject{};
		// Class object instance
		HSQOBJECT classObjectInstance{};
	};
}
#endif // CLASS_H
