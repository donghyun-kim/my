#include "stdafx.h"
#include "OverlapdSocket.h"
#include "OverlapdSocketPimpl.h"

#include "Proactor.h"

OverlapdSocketBase::OverlapdSocketBase(ActorBase& actor) : SocketBase(actor),  proactor_(static_cast<Proactor&>(actor))
, socket_(INVALID_SOCKET), listen_socket_(INVALID_SOCKET)
{
    action_[ActionAccept] = new AcceptAction(*this, proactor_);
    //action_[ActionSend] = new TCPSocketSend(*this)
    //action_[ActionRecv] = new TCPSocketRecive(*this)
    //     action_[ActionDisconnect] = new TCPSocketDisconnect(*this);
}

bool OverlapdSocketBase::Initialize()
{
    WORD port = 999;

    listen_socket_ = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);

    if (listen_socket_ == INVALID_SOCKET)
        return false;

    SOCKADDR_IN    server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    // 연결 시켜 오기를 기다리자
    if (bind(listen_socket_, (SOCKADDR*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR)
        return false;

    // 온것을 알아 차린다
    if (listen(listen_socket_, SOMAXCONN) == SOCKET_ERROR)
        return false;

    if (proactor_.Register(reinterpret_cast<HANDLE>(listen_socket_)) == false)
        return false;

    return true;
}
bool OverlapdSocketBase::Send()
{
    //action_[ActionSend]->buffer;
    return false;
}

bool OverlapdSocketBase::Recv()
{
    //static_cast<TCPSocketR> action_[ActionRecv]->buffer
    return false;
}
