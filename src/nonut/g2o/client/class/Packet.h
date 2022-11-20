#pragma once
#ifndef PACKET_H
#define PACKET_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Packet : public Class
	{
	public:
		Packet();

		// Methods
		Function<void> reset;
		Function<void, int> send;
		Function<void, bool> writeBool;
		Function<void, int> writeInt8;
		Function<void, int> writeUInt8;
		Function<void, int> writeInt16;
		Function<void, int> writeUInt16;
		Function<void, int> writeUInt32;
		Function<void, float> writeFloat;
		Function<void, std::string> writeString;
		Function<bool> readBool;
		Function<int> readInt8;
		Function<int> readUInt8;
		Function<int> readInt16;
		Function<int> readUInt16;
		Function<int> readUInt32;
		Function<float> readFloat;
		Function<std::string> readString;
	};
}
#endif
