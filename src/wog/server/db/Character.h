#ifndef WOG_SERVER_DB_CHARACTER_H
#define WOG_SERVER_DB_CHARACTER_H

#include "CommonHeader.h"

namespace wog
{
	struct Character
	{
		PrimaryKey id;
		ForeignKey accountId;
		String name;
	};
}
#endif // WOG_SERVER_DB_CHARACTER_H
