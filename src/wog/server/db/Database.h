#ifndef WOG_SERVER_DATABASE_H
#define WOG_SERVER_DATABASE_H

#include <sqlite_orm.h>
#include "User.h"
#include "Character.h"

namespace orm = sqlite_orm;

namespace wog
{
	static inline auto initStorage(const std::string& dbName = "wog.sqlite")
	{
		return orm::make_storage(dbName,
		                         orm::make_table("users",
		                                         orm::make_column("id", &User::id, orm::primary_key().autoincrement()),
		                                         orm::make_column("username", &User::username, orm::unique()),
		                                         orm::make_column("password", &User::password)),
		                         orm::make_table("characters",
		                                         orm::make_column("id", &Character::id,
		                                                          orm::primary_key().autoincrement()),
		                                         orm::make_column("account_id", &Character::accountId),
		                                         orm::make_column("name", &Character::name),
		                                         orm::foreign_key(&Character::accountId).references(&User::id))
		);
	}

	using Storage = decltype(initStorage(""));

#define DB_STORAGE wog::Database::get()->storage

	class Database
	{
	public:
		Database(const Database&) = delete;
		Database(Database&&) = delete;
		Database& operator=(const Database&) = delete;
		Database& operator=(Database&&) = delete;

		~Database() = default;

		static Database* get();
		static void disconnect();

		Storage storage;

	protected:
		Database();

		static inline Database* instance = nullptr;
	};
}
#endif // WOG_SERVER_DATABASE_H
