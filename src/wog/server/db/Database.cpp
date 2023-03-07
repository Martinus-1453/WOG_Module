#include "Database.h"
#include "event/ServerEventHandlers.h"

namespace wog
{
	Database* Database::get()
	{
		if (instance == nullptr)
		{
			instance = new Database();
		}
		return instance;
	}

	void Database::disconnect()
	{
		delete instance;
		instance = nullptr;
	}

	Database::Database() : storage(initStorage())
	{
		storage.sync_schema(true);
		storage.pragma.journal_mode(orm::journal_mode::WAL);

		g2o::ServerEventHandlers::onExitHandler.emplace_back([]
		{
			disconnect();
		});
	}
}
