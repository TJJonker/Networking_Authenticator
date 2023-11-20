#pragma once
#include <TwoNet/Buffer/Buffer.h>

namespace TwoNet {
	class TwoProt {

	public:
		static void SerializeData(TwoNet::Buffer& buffer, const char* data, size_t dataLength);
		static const char* DeserializeData(TwoNet::Buffer& buffer);
	};
}