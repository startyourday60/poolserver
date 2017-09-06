#include "Crypto.h"
#include "Gost.h"

namespace Crypto
{
	BinaryData GOSTD(BinaryData data)
	{
		uint8_t hash1[64];
		i2p::crypto::GOSTR3411_2012_512 (&data[0], data.size (), hash1);	
		std::vector<byte> hash(32);
		i2p::crypto::GOSTR3411_2012_256 (hash1, 64, &hash[0]);
		return 	std::vector<byte>(hash.begin(), hash.end());
	}
}
