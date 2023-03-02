#ifndef NONUT_G2O_SHARED_CLASS_MDS_H
#define NONUT_G2O_SHARED_CLASS_MDS_H
#include "pch.h"
#include "Function.h"
#include "StaticClass.h"

namespace nonut::g2o
{
	class Mds : public StaticClass
	{
	public:
		static Mds* get();

		Function<Int, String> id;
		Function<String, Int> name;
	private:
		Mds();
		static inline Mds* instance = nullptr;

	};
}
#endif // NONUT_G2O_SHARED_CLASS_MDS_H
