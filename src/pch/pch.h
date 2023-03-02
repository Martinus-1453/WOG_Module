#ifndef PCH_PCH_H
#define PCH_PCH_H
#define QUOTIFY(arg) #arg
#define STRINGIFY(arg) QUOTIFY(arg)

#define SCRAT_EXPORT // Used to get SQRAT_API macro for sqmodule_load func (export function)

#include "module_api.h"
#include "squirrel_api.h"
#include "sqrat.h"
#include <optional>

using Int = SQInteger;
using UInt = SQUnsignedInteger;
using UInt32 = SQUnsignedInteger32;
using Float = SQFloat;
using Bool = SQBool;
using String = std::string;

constexpr SQObject SQ_NULL{ OT_NULL };

using PrimaryKey = int;
using ForeignKey = std::optional<int>;

namespace nonut::g2o{}
namespace g2o = nonut::g2o;


#endif // PCH_PCH_H
