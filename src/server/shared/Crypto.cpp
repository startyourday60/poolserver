#include "Crypto.h"
#include "Gost.h"

namespace Crypto
{
	BinaryData GOSTD(BinaryData data)
	{
		uint8_t hash1[64], hash2[32];
		i2p::crypto::GOSTR3411_2012_512 (&data[0], data.size (), hash1);	
		i2p::crypto::GOSTR3411_2012_256 (hash1, 64, hash2);
		std::vector<byte> hash;
		// To Little Endian. TODO implement faster
		for (int i = 0; i < 32; i++)
			hash.push_back (hash2[31-i]); 
		return 	hash;
	}

	BinaryData GOSTD(BinaryData data1, BinaryData data2)
	{
		BinaryData data3 = data1;
    	data3.insert(data3.end(), data2.begin(), data2.end());
		uint8_t hash1[64];
		std::vector<byte> hash(32);
		i2p::crypto::GOSTR3411_2012_512 (&data3[0], data3.size (), hash1);	
		i2p::crypto::GOSTR3411_2012_256 (hash1, 64, &hash[0]);
		// we don't convert to Little Endian here
		return 	hash;
	}
}
