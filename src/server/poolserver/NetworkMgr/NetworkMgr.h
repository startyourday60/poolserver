#ifndef NETWORKMGR_H_
#define NETWORKMGR_H_

// Provides high level interaction with gostcoin daemon

#include "JSONRPC.h"
#include "Gostcoin.h"
#include "Log.h"

#include <vector>
#include <boost/asio.hpp>
#include <boost/function.hpp>
#include <boost/thread/mutex.hpp>

using namespace boost;

typedef boost::function<void (Gostcoin::BlockPtr /*blockTmpl*/, bool /*newBlock*/)> FBlockNotify;

class NetworkMgr
{
    // Singleton
private:
    static NetworkMgr* singleton;
public:
    
    static NetworkMgr* Instance()
    {
        return singleton;
    }
    static void Initialize(asio::io_service& io_service)
    {
        singleton = new NetworkMgr(io_service);
    }
    
public:
    NetworkMgr(asio::io_service& io_service);
    ~NetworkMgr();
    
    // Gostcoin daemon connection
    void Connect(JSONRPCConnectionInfo coninfo);
    
    // Get new block template
    void UpdateBlockTemplate();
    
    // Submit new block
    bool SubmitBlock(Gostcoin::Block block);
    
    // Checking for blocks
    void BlockCheck();
    void BlockCheckTimerStart();
    void BlockCheckTimerExpired(const boost::system::error_code& /*e*/);
    
    // Bind for receiving block notifications
    void BlockNotifyBind(FBlockNotify f);
    
    // Block notify timer
    void BlockNotifyTimerStart();
    void BlockNotifyTimerExpired(const boost::system::error_code& /*e*/);
    
    // Send block notification to all subscribers
    void BlockNotifySend(bool newBlock = false);
    
private:
    // Holds subscriptions for block notifications
    std::vector<FBlockNotify> _blockNotifyBinds;
    boost::asio::deadline_timer _blockNotifyTimer;
    
    // Checking for new blocks
    boost::asio::deadline_timer _blockCheckTimer;
    boost::mutex _mtxBlockCheck;
    uint32 _blockHeight;
    
    // Connections to gostcoin rpc
    std::vector<JSONRPC*> _cons;
    
    // Current block template
    Gostcoin::BlockPtr _curBlockTmpl;
    boost::mutex _mtxBlockTmpl;
    
    // ASIO
    asio::io_service& _io_service;
};

#endif
