#include "Transaction.h"
#include "Util.h"

namespace Bitcoin
{
    BinaryData Transaction::GetHash()
    {
        ByteBuffer buf;
        buf << *this;
        return Crypto::GOSTD(buf.Binary());
    }
}
