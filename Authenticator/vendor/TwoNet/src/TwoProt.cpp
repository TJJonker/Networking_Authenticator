#include "TwoNet/tpch.h"
#include "TwoNet/Protocols/TwoProt.h"

namespace TwoNet {
	void TwoProt::SerializeData(TwoNet::Buffer& buffer, const char* data, size_t dataLength)
	{
		buffer.SerializeUInt_16((uint16_t)dataLength);
		buffer.SerializeData(data, dataLength);
	}

	const char* TwoProt::DeserializeData(TwoNet::Buffer& buffer)
	{
		uint16_t dataLength = buffer.DeserializeUInt_16();
		if (dataLength == 0)
			return nullptr;
		return buffer.DeserializeData(dataLength);
	}
}