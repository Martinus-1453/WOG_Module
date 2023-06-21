#ifndef WOG_SERVER_DB_USER_H
#define WOG_SERVER_DB_USER_H

#include "CommonHeader.h"
#include "WogHeader.h"

namespace wog
{
	struct User
	{
		PrimaryKey id;
		String username;
		String password;
	};
}

#endif // WOG_SERVER_DB_USER_H
