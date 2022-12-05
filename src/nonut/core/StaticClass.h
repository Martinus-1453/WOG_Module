#ifndef NONUT_CORE_STATIC_CLASS_H
#define NONUT_CORE_STATIC_CLASS_H

#include "Function.h"
#include "Property.h"

#define METHOD_CTOR(methodName) methodName(#methodName, this->classObjectInstance, this->classObject)
#define PROPERTY_CTOR(propertyName) propertyName(#propertyName, this->classObjectInstance)

namespace nonut
{
	class StaticClass
	{
	public:
		StaticClass(String className);
		~StaticClass();

	protected:
		// Object holding information about class
		SQObject classObject{};
		// Class object instance
		SQObject classObjectInstance{};
	};
}
#endif // NONUT_CORE_STATIC_CLASS_H
