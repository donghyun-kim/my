#pragma once

#include "TCPSocket.h"
#include "EventHandler.h"

#define BUFSIZE 8192

class TCPSocket::Action : public OverlappedEventHandler
{
public:
	TCPSocket::Action(TCPSocket& tcp_socket) : tcp_socket_(tcp_socket) {}
	
	//virtual bool Init() = 0;

protected:
	TCPSocket& tcp_socket_;
};

class TCPSocketAccept : public TCPSocket::Action
{
public:
	TCPSocketAccept(TCPSocket& tcp_socket);
	virtual ~TCPSocketAccept();

	virtual bool init();

	virtual void Success(DWORD bytes_transferred );
	virtual void Failed(DWORD error);

private:
	char buffer_[BUFSIZE];
};
