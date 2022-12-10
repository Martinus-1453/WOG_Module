#include "pch.h"
#include "Class.h"

using namespace SqModule;

namespace nonut
{
	Class::Class(SQObject classObjectInstance, String className) : classObjectInstance(classObjectInstance)
	{
		const auto top = sq_gettop(vm);
		sq_addref(vm, &this->classObject);

		sq_pushroottable(vm); //push root table
		sq_pushstring(vm, className.c_str(), className.length()); //push class name

		if (sq_get(vm, -2) == SQ_OK) //retrieve class
		{
			sq_getstackobj(vm, -1, &classObject);
			sq_addref(vm, &classObject);
		}

		sq_settop(vm, top);
	}

	Class::Class(String className)
	{
		const auto top = sq_gettop(vm);

		sq_pushroottable(vm); //push root table
		sq_pushstring(vm, className.c_str(), className.length()); //push class name

		if (sq_get(vm, -2) == SQ_OK) //retrieve class
		{
			sq_getstackobj(vm, -1, &classObject);
			sq_addref(vm, &classObject);
			if (sq_createinstance(vm, -1) == SQ_OK) //create class instance
			{
				//1. Get object ptr
				sq_getstackobj(vm, -1, &classObjectInstance); //retrieve object
				sq_addref(vm, &classObjectInstance); //Add ref thanks to which object will not be immediately deleted
				sq_pop(vm, 1); // pop class instance
			}
		}
		sq_settop(vm, top); // TODO: FIX LEAK PROPERLY
	}

	Class::~Class()
	{
		sq_release(vm, &classObject);
		sq_release(vm, &classObjectInstance);
		sq_resetobject(&classObject);
		sq_resetobject(&classObjectInstance);
	}

	SQObject Class::getInstance()
	{
		return classObjectInstance;
	}
}
