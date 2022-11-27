#ifndef PCH_PCH_H
#define PCH_PCH_H
#define QUOTIFY(arg) #arg
#define STRINGIFY(arg) QUOTIFY(arg)

#define SCRAT_EXPORT // Used to get SQRAT_API macro for sqmodule_load func (export function)

#include "module_api.h"
#include "squirrel_api.h"
#include "sqrat.h"

using Int = SQInteger;
using UInt = SQUnsignedInteger;
using UInt32 = SQUnsignedInteger32;
using Float = SQFloat;
using Bool = SQBool;
using String = std::string;


#endif // PCH_PCH_H
