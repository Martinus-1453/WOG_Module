#ifndef NONUT_CORE_CLASS_H
#define NONUT_CORE_CLASS_H
#include "pch.h"
#include <string>

#include "Function.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "Property.h"
#include "Instance.h"

#define METHOD_CTOR(methodName) methodName(#methodName, this->classObjectInstance, this->classObject)
#define PROPERTY_CTOR(propertyName) propertyName(#propertyName, this->classObjectInstance)
#define COPY_CTOR(type) type(const type& other) : type(other.getInstance()){} \
	type& operator=(const type& other) = delete

namespace nonut
{
	static constexpr auto CONSTRUCTOR_NAME = "constructor";

	class Class : public Instance
	{
	public:
		Class(const String& className, SQObject classObjectInstance = SQ_NULL);
		virtual ~Class();

		[[nodiscard]] SQObject getInstance() const override;

	protected:
		// Object holding information about class
		SQObject classObject{};
		// Class object instance
		SQObject classObjectInstance{};

		template <typename... Args>
		void classCtor(Args ... args)
		{
			Function<void, Args...> ctor(CONSTRUCTOR_NAME, classObjectInstance, classObject);
			ctor(std::forward<Args>(args)...);
		}
	};
}
#endif // NONUT_CORE_CLASS_H
