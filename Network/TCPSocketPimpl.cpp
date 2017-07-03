#include "stdafx.h"
#include "TCPSocketPimpl.h"
#include "TCPSocket.h"

#include <winsock2.h>
#include <ws2tcpip.h>
#include <mswsock.h>


TCPSocketAccept::TCPSocketAccept(TCPSocket& tcp_socket) : TCPSocket::Action(tcp_socket)
{
}

TCPSocketAccept::~TCPSocketAccept()
{

}

bool TCPSocketAccept::init()
{
	DWORD byte_transferred;

	BOOL ret = AcceptEx(tcp_socket_.socket_, 
						tcp_socket_.listen_socket_, 
						buffer_, 
						0,
						sizeof(SOCKADDR_IN) + 16,
						sizeof(SOCKADDR_IN) + 16,
						&byte_transferred,
						static_cast<OVERLAPPED*>(tcp_socket_.action_[TCPSocket::ActionAccept]) );

	int error = WSAGetLastError();

	if (ret == FALSE && error != ERROR_IO_PENDING) 
		return false;
	
	return true;
}

void TCPSocketAccept::Success( DWORD bytes_transferred )
{
	// next recv?
}

void TCPSocketAccept::Failed( DWORD error )
{
	// error
}
