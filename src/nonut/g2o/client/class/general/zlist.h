#ifndef NONUT_G2O_CLIENT_CLASS_ZLIST_H
#define NONUT_G2O_CLIENT_CLASS_ZLIST_H

#include "Class.h"

namespace nonut::g2o
{
	template<typename T>
	class zlist : public Class
	{
	public:
		zlist() : zlist(SQ_NULL)
		{
			classCtor();
		}
		zlist(SQObject object) :
			Class("zlist", object),
			METHOD_CTOR(len),
			METHOD_CTOR(isIn),
			METHOD_CTOR(insert),
			METHOD_CTOR(remove)
		{
		}
		COPY_CTOR(zlist);

		Function<Int> len;
		Function<Bool, T> isIn;
		Function<void, T> insert;
		Function<void, T> remove;
	};
}
#endif //NONUT_G2O_CLIENT_CLASS_ZLIST_H