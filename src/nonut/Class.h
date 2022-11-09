#pragma once
#ifndef CLASS_H
#define CLASS_H
#include "pch.h"
#include <string>

#include "Function.h"

#define METHOD_CTOR(methodName) methodName(#methodName, this->classObjectInstance, this->classObject)
#define PROPERTY_CTOR(propertyName) propertyName(#propertyName, this->classObjectInstance)

namespace nonut
{
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

		template<typename... Args>
		void ClassCtor(Args... args)
		{
			Function<void, Args... > ctor(CONSTRUCTOR_NAME, classObjectInstance, classObject);
			ctor(std::forward<Args>(args)...);
		}
	};
}
#endif // CLASS_H
