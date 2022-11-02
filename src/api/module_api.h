#ifndef _MODULE_API_H
#define _MODULE_API_H

#include <sqmodule.h>

namespace SqModule
{
	extern HSQUIRRELVM vm;
	extern HSQAPI api;

	void Initialize(HSQUIRRELVM vm, HSQAPI api);
	void Print(const SQChar* msg);
	void Error(const SQChar* msg);
}

#endif