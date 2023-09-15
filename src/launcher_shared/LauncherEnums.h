#ifndef LAUNCHER_SHARED_LAUNCHERENUMS_H_
#define LAUNCHER_SHARED_LAUNCHERENUMS_H_

namespace wog::launcher
{
	constexpr auto OBJECT_G2O = "g2o";

	constexpr auto MESSAGE_TYPE_CALLBACK = "CALLBACK";
	constexpr auto MESSAGE_TYPE_GETTER = "GETTER";
	constexpr auto MESSAGE_TYPE_SETTER = "SETTER";

	enum class MessageType
	{
		Callback,
		Getter,
		Setter,
	};

	const char* getMessageTypeName(MessageType type);
}
#endif // LAUNCHER_SHARED_LAUNCHERENUMS_H_
