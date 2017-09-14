#include "stdafx.h"
#include "Network.h"
#include "Proactor.h"
#include "OverlapdSocket.h"
#include "Log.h"
Network::Network(const WCHAR* ip_addres, unsigned short port) : actor_(nullptr), socket_(nullptr)
{
   
}

Network::~Network()
{
    if (socket_)
        delete socket_;

    if (actor_)
        delete actor_;
}

bool Network::Initialize()
{
    Log::Getinstance()->Initialize();

    Log::Getinstance()->Write(Log::Notice, L"Test");

    if (actor_ || socket_)
        return false;

    WSADATA wsadata;
    WORD version;
    int error_code;

    version = MAKEWORD(2, 2);

    error_code = WSAStartup(version, &wsadata);
    if (error_code != NO_ERROR || LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2)
    {
        return false;
    }

    actor_ = new Proactor();
    socket_ = new OverlapdSocketBase(*static_cast<Proactor*>(actor_));

    if (actor_->Initialize() == false)
    {
        return false;
    }

    if (socket_->Initialize() == false)
    {
        return false;
    }

    return true;
}
