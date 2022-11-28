#ifndef NONUT_G2O_SHARED_PACKET_TYPES_H
#define NONUT_G2O_SHARED_PACKET_TYPES_H
#include "pch.h"

namespace nonut
{
	enum class ClientPacketType : Int
	{
		HelloServer,
		NumberOfPacketTypes // Only for reference
	};

	enum class ServerPacketType : Int
	{
		HelloClient,
		NumberOfPacketTypes // Only for reference
	};

}
#endif // NONUT_G2O_SHARED_PACKET_TYPES_H
