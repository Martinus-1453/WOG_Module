#pragma once
#ifndef OBJECT_H
#define OBJECT_H
#include "pch.h"

#include <tuple>
#include <string>
#include <array>

#include "Property.h"

namespace nonut {
	class Object
	{
	public:
		Object(SQObject object);
		~Object();

		template<typename... Rets>
		std::tuple<Rets...> Unpack(std::array < std::string, { sizeof...(Rets) } > argNames);

	private:
		SQObject object;
	};

	template<typename... Rets>
	std::tuple<Rets...> Object::Unpack(std::array < std::string, { sizeof...(Rets) } > argNames)
	{
		std::tuple<Rets...> result;
		std::apply([](auto ...x) {std::make_tuple(x.do_something()...); }, result);
		return result;
	}
}
#endif //OBJECT_H
