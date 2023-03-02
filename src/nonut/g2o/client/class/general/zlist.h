#ifndef NONUT_G2O_CLIENT_CLASS_ZLIST_H
#define NONUT_G2O_CLIENT_CLASS_ZLIST_H

#include "Class.h"

namespace nonut::g2o
{
	class zlist : public Class
	{
	public:
		zlist();
		zlist(SQObject object);
		COPY_CTOR(zlist);

		Function<Int> len;
		Function<Bool, SQUserPointer> isIn;
		Function<void, SQUserPointer> insert;
		Function<void, SQUserPointer> remove;
	};
}
#endif //NONUT_G2O_CLIENT_CLASS_ZLIST_H