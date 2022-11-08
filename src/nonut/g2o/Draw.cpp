#include "pch.h"
#include "Draw.h"

#include <utility>

#include "nonut/Function.h"

namespace nonut::g2o
{
	using namespace nonut;
	Draw::Draw(int x, int y, std::string text) : Class("Draw"), visible("visible", this->classObjectInstance)
	{
		Function<void, int, int, std::string> ctor(CONSTRUCTOR_NAME, classObjectInstance, classObject);
		ctor(x, y, std::move(text));
		visible.Set(true);
	}
}
