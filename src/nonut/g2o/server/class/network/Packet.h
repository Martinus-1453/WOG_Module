#ifndef NONUT_G2O_SERVER_CLASS_PACKET
#define NONUT_G2O_SERVER_CLASS_PACKET
#include <string>

#include "Class.h"
#include "CustomTypes.h"
#include "PacketTypes.h"

namespace nonut::g2o
{
	class Packet : public Class
	{
	public:
		Packet(ServerPacketType packetType);
		explicit Packet(SQObject object);

		[[nodiscard]] ClientPacketType getType() const;

		// Methods
		Function<void> reset;
		Function<void, Int, Int> send;
		Function<void, Int> sendToAll;
		Function<void, Bool> writeBool;
		Function<void, Int> writeInt8;
		Function<void, Int> writeUInt8;
		Function<void, Int> writeInt16;
		Function<void, Int> writeUInt16;
		Function<void, Int> writeInt32;
		Function<void, Int> writeUInt32;
		Function<void, Float> writeFloat;
		Function<void, String&> writeString;
		Function<Bool> readBool;
		Function<Int> readInt8;
		Function<Int> readUInt8;
		Function<Int> readInt16;
		Function<Int> readUInt16;
		Function<Int> readInt32;
		Function<Int> readUInt32;
		Function<Float> readFloat;
		Function<String> readString;

	private:
		ClientPacketType packetType;
	};
}
#endif // NONUT_G2O_SERVER_CLASS_PACKET