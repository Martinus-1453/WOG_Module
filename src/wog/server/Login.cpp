#include "Login.h"
#include "event/ServerEventHandlers.h"
#include "db/Database.h"
#include <ranges>

#include "function/ServerFunctions.h"

using namespace sqlite_orm;

namespace wog
{
	Login* Login::get()
	{
		if (instance == nullptr)
		{
			instance = new Login();
		}
		return instance;
	}

	Login::Login()
	{
		g2o::ServerEventHandlers::onPlayerCommandHandler.emplace_back(
			[](const Int id, const String command, const std::vector<String> params)
			{
				if (command == "register")
				{
					if (params.size() != 2) return;

					String message;

					try
					{
						const User newUser{-1, params[0], params[1]};
						const auto newId = DB_STORAGE.insert<User>(newUser);
						message = "Account: " + params[0] + " registered with id=" + std::to_string(newId) + ".";
					}
					catch (const std::system_error& e)
					{
						message = e.what();
					}

					S_F->sendPlayerMessageToPlayer(id, id, 255, 255, 255, message);
				}

				if (command == "login")
				{
					if (params.size() != 2) return;

					String message;

					try
					{
						const auto users = DB_STORAGE.get_all<User>(
							where(c(&User::username) == params[0] and c(&User::password) == params[1]));
						if (users.size() == 1)
						{
							message = "Account: " + users[0].username + " Password: " + users[0].password;
						}
						else
						{
							throw std::system_error(0, std::generic_category(),
							                        "account does not exist or wrong password");
						}
					}
					catch (const std::system_error& e)
					{
						message = e.what();
					}

					S_F->sendPlayerMessageToPlayer(id, id, 255, 255, 255, message);
				}
			});
	}
}
