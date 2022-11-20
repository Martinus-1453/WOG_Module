#define QUOTIFY(arg) #arg
#define STRINGIFY(arg) QUOTIFY(arg)

#define SCRAT_EXPORT // Used to get SQRAT_API macro for sqmodule_load func (export function)

#include "module_api.h"
#include "squirrel_api.h"
#include "sqrat.h"
