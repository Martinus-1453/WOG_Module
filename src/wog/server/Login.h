#ifndef WOG_SERVER_LOGIN_H
#define WOG_SERVER_LOGIN_H

namespace wog
{
	class Login
	{
	public:
		static Login* get();

	protected:
		Login();

		static inline Login* instance = nullptr;
	};
}
#endif // WOG_SERVER_LOGIN_H
