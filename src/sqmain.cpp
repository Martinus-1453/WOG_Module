#include "pch.h"
using namespace SqModule;

class Draw {
public:
	Draw(int x, int y, std::string text)
	{
		sq_pushroottable(vm); //push root table

		sq_pushstring(vm, "Draw", -1); //push class name

		if (sq_get(vm, -2) == SQ_OK) //retrieve class
		{

			if (sq_createinstance(vm, -1) == SQ_OK) //create class instance
			{
				//1. Get object ptr
				sq_getstackobj(vm, -1, &object); //retrieve object
				sq_addref(vm, &object); //Add ref thanks to which object will not be immediately deleted
				sq_pop(vm, 1); // pop class instance

				//2. Call ctor
				sq_pushstring(vm, "constructor", -1);
				sq_get(vm, -2);
				sq_pushobject(vm, object);
				sq_pushinteger(vm, x);
				sq_pushinteger(vm, y);
				sq_pushstring(vm, text.c_str(), text.length());
				auto result = sq_call(vm, 4, SQFalse, SQFalse);
				// No return value
			}
		}
		sq_pop(vm, 3);
	}

	~Draw()
	{

	}

	bool GetIsVisible() {
		SQBool result = false;
		sq_pushobject(vm, object);
		sq_pushstring(vm, "visible", -1);

		if (SQ_SUCCEEDED(sq_get(vm, -2))) // pops visible
		{
			sq_getbool(vm, -1, &result);
			sq_pop(vm, 1); // pops result
		}

		sq_pop(vm, 1); // pops object

		return result;
	}

	void SetIsVisible(bool isVisible) {
		sq_pushobject(vm, object);

		sq_pushstring(vm, "visible", -1);

		sq_pushbool(vm, isVisible);

		auto result = sq_set(vm, -3); // pops visible and isVisible

		sq_pop(vm, 1); // pops object
	}

private:
	HSQOBJECT object = {OT_NULL};
};

extern "C" SQRESULT SQRAT_API sqmodule_load(HSQUIRRELVM vm, HSQAPI api) {
	SqModule::Initialize(vm, api);
	Sqrat::DefaultVM::Set(vm);
	Sqrat::RootTable(vm).GetFunction("print").Execute(std::string("Hello there from module :)"));
	Draw* draw = new Draw(0, 0, "dupa");
	draw->SetIsVisible(true);
	return SQ_OK;
}
