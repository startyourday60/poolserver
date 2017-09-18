#include "Transaction.h"
#include "Util.h"

namespace Gostcoin
{
    BinaryData Transaction::GetHash()
    {
        ByteBuffer buf;
        buf << *this;
        return Crypto::GOSTD(buf.Binary());
    }
}
