#include "stdafx.h"
#include "TCPSocket.h"
#include "Proactor.h"
#include "TCPSocketPimpl.h"

TCPSocket::TCPSocket(Actor& proactor) : proactor_(proactor)
{
    action_[ActionAccept] = new TCPSocketAccept(*this);
    //action_[ActionSend] = new TCPSocketSend(*this)
    //action_[ActionRecv] = new TCPSocketRecive(*this)
    //     action_[ActionDisconnect] = new TCPSocketDisconnect(*this);
}

TCPSocket::~TCPSocket()
{
    
}

bool TCPSocket::Init()
{
    WORD port = 999;

    listen_socket_ = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);

    if (listen_socket_ == INVALID_SOCKET)
        return false;

    SOCKADDR_IN    server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);
    
    if (bind(listen_socket_, (SOCKADDR*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR)
        return false;

    if (listen(listen_socket_, SOMAXCONN) == SOCKET_ERROR)
        return false;

    socket_ = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
    if(socket_ == INVALID_SOCKET )
        return false;

    if (proactor_.Register(reinterpret_cast<HANDLE>(listen_socket_)) == false)
        return false;

    return true;
}

bool TCPSocket::Send()
{
    //action_[ActionSend]->buffer;
}

bool TCPSocket::Recv()
{
    //static_cast<TCPSocketR> action_[ActionRecv]->buffer
}
