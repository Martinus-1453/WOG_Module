#ifndef WOG_SHARED_PACKETHELPER_H
#define WOG_SHARED_PACKETHELPER_H

#include "WogHeader.h"
#include <type_traits>

namespace wog
{
	template<typename PacketType>
	class PacketHelper
	{
	public:
		PacketHelper() = default;

		template<typename T>
		void write(T value)
		{
			if constexpr (std::is_same_v<T, bool>)
				packet.writeBool(value);
			if constexpr (std::is_same_v<T, int8_t>)
				packet.writeInt8(value);
			if constexpr (std::is_same_v<T, uint8_t>)
				packet.writeUInt8(value);
			if constexpr (std::is_same_v<T, int16_t>)
				packet.writeInt16(value);
			if constexpr (std::is_same_v<T, uint16_t>)
				packet.writeUInt16(value);
			if constexpr (std::is_same_v<T, int32_t>)
				packet.writeInt32(value);
			if constexpr (std::is_same_v<T, uint32_t>)
				packet.writeUInt32(value);
			if constexpr (std::is_same_v<T, float>)
				packet.writeFloat(value);
			if constexpr (std::is_same_v<T, String>)
				packet.writeString(value);
		}

		template<typename T>
		T read(T value)
		{
			if constexpr (std::is_same_v<T, bool>)
				return packet.readBool(value);
			if constexpr (std::is_same_v < T, int8_t>)
				return packet.readInt8(value);
			if constexpr (std::is_same_v<T, uint8_t>)
				return packet.readUInt8(value);
			if constexpr (std::is_same_v<T, int16_t>)
				return packet.readInt16(value);
			if constexpr (std::is_same_v<T, uint16_t>)
				return packet.readUInt16(value);
			if constexpr (std::is_same_v<T, int32_t>)
				return packet.readInt32(value);
			if constexpr (std::is_same_v<T, uint32_t>)
				return packet.readUInt32(value);
			if constexpr (std::is_same_v<T, float>)
				return packet.readFloat(value);
			if constexpr (std::is_same_v<T, String>)
				return packet.readString(value);
		}

		PacketType& Build();

	private:
		PacketType packet;
	};	
}
#endif //WOG_SHARED_PACKETHELPER_H