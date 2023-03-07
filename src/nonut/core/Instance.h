#ifndef NONUT_CORE_INSTANCE_H
#define NONUT_CORE_INSTANCE_H

namespace nonut
{
	class Instance
	{
	public:
		[[nodiscard]] virtual SQObject getInstance() const = 0;
	};
}
#endif //NONUT_CORE_INSTANCE_H
