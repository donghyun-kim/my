#include "stdafx.h"
#include "Network.h"
#include "TCPSocket.h"

Network::Network(const WCHAR* ip_addres, unsigned short port)
{
    proactor_ = new Proactor();
    tcp_socket_ = new TCPSocket(*proactor_);
}

Network::~Network()
{
    
}
