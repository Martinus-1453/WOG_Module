#ifndef WOG_SHARED_WOGHEADER_H_
#define WOG_SHARED_WOGHEADER_H_
#include "CommonHeader.h"
#include <vector>
#include <optional>

namespace wog
{
	constexpr SQObject SQ_NULL{ OT_NULL };

	using Int = nonut::Int;
	using UInt = nonut::UInt;
	using UInt32 = nonut::UInt32;
	using Float = nonut::Float;
	using Bool = nonut::Bool;
	using String = nonut::String;

	using PrimaryKey = int;
	using ForeignKey = std::optional<int>;

	template<typename T>
	using Vector = std::vector<T>;

	template<typename T>
	class Singleton
	{
	protected:
		Singleton() = default;
		static inline T* instance = nullptr;

	public:
		static T* get()
		{
			if (instance == nullptr)
			{
				instance = new T();
			}
			return instance;
		}

		static void free()
		{
			if (instance != nullptr)
			{
				delete instance;
				instance = nullptr;
			}
		}
	};
}
#endif // WOG_SHARED_WOGHEADER_H_
