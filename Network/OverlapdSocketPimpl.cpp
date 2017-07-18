#include "stdafx.h"
#include "OverlapdSocketPimpl.h"
#include "OverlapdSocket.h"


AcceptAction::AcceptAction(OverlapdSocketBase& socket, Proactor& proactor) : OverlapdSocketBase::OverlappedAction(socket, proactor)
{
}

AcceptAction::~AcceptAction()
{

}

bool AcceptAction::init()
{
    base_.socket_ = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (base_.socket_ == INVALID_SOCKET)
        return false;

    DWORD byte_transferred;

    // 신호가 온것을 받아들임
    BOOL ret = AcceptEx(base_.socket_, 
                        base_.listen_socket_, 
                        buffer_, 
                        0,
                        sizeof(SOCKADDR_IN) + 16,
                        sizeof(SOCKADDR_IN) + 16,
                        &byte_transferred,
                        static_cast<OVERLAPPED*>(base_.action_[OverlapdSocketBase::ActionAccept]) );

    int error = WSAGetLastError();

    if (ret == FALSE && error != ERROR_IO_PENDING) 
        return false;
    
    return true;
}

void AcceptAction::Success( DWORD bytes_transferred )
{
    // next recv?
}

void AcceptAction::Failed( DWORD error )
{
    // error
}
