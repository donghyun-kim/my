#include "stdafx.h"
#include "Network.h"
#include "Proactor.h"
#include "OverlapdSocket.h"

Network::Network(const WCHAR* ip_addres, unsigned short port)
{
    actor_ = new Proactor();
    socket_ = new OverlapdSocketBase(*actor_);

    actor_->Initialize();
    socket_->Initialize();
}

Network::~Network()
{
    
}
