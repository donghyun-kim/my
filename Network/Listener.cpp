#include "stdafx.h"
#include "Listener.h"
#include "Proactor.h"

Listener::Listener(Proactor& iocp) : proactor_handle_(0)
{
	
}

Listener::~Listener()
{

}

bool Listener::Initialize(USHORT port)
{
// 	server_socket_ = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
// 
// 	if (server_socket_ == INVALID_SOCKET)
// 		return false;
// 
// 	SOCKADDR_IN	server_addr;
// 	server_addr.sin_family = AF_INET;
// 	server_addr.sin_port = htons(port);
// 	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
// 
// 	if (bind(server_socket_, (SOCKADDR*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR)
// 		return false;
// 
// 	if (listen(server_socket_, SOMAXCONN) == SOCKET_ERROR)
// 		return false;
// 
 	return true;
}


void Listener::DoWork()
{
// 	SOCKADDR_IN	client_addr;
// 	SOCKET clinet_socket = INVALID_SOCKET;
// 
// 	ZeroMemory(&client_addr, sizeof(client_addr));
// 	int nSizeClntAddr = sizeof(client_addr);
// 
// 	while (true)
// 	{
// 		DWORD dwRecvByte = 0;
// 		DWORD dwFlags = 0;
// 
// 		clinet_socket = accept(server_socket_, (SOCKADDR*)&client_addr, &nSizeClntAddr);
// 
// 		if (clinet_socket == INVALID_SOCKET)
// 		{
// 			if (WSAEINTR == WSAGetLastError())
// 			{
// 				//m_Log.EventLog(2, "AcceptThread", GetStringErrCode(WSAEINTR));
// 				//return 0;
// 			}
// 		}
// 
// 		DWORD nonblock = 1;
// 		if (ioctlsocket(clinet_socket, FIONBIO, &nonblock) == SOCKET_ERROR)
// 			continue;
// 
// 		int	nZero = 0;
// 		if (SOCKET_ERROR == setsockopt(clinet_socket, SOL_SOCKET, SO_RCVBUF, (const TCHAR*)&nZero, sizeof(nZero)))
// 			continue;
// 
// 		if (SOCKET_ERROR == setsockopt(clinet_socket, SOL_SOCKET, SO_SNDBUF, (const TCHAR*)&nZero, sizeof(nZero)))
// 			continue;
// 
// 		LIB_SESSIONDATA* pSession = m_SessionPool.CreateSession();
// 		pSession->m_SocketCtx.clntSocket = clinet_socket;
// 		pSession->SetClientAddr(&clntAddr);
// 
// 		m_SessionPool.InsertSession(pSession);
// 
// 		if (m_Proactor.REGISTER_CLIENT(hClntSock, pSession) != TRUE)
// 		{
// 			//			m_Log.EventLog();
// 			continue;
// 		}
// 
// 		int nRet = WSARecv(hClntSock, &(pSession->m_SocketCtx.recvContext->wsaBuf), 1, &dwRecvByte, &dwFlags, &(pSession->m_SocketCtx.recvContext->overlapped), NULL);
// 
// 		if (SOCKET_ERROR == nRet)
// 		{
// 			int ErrCode = WSAGetLastError();
// 			if (ErrCode != WSA_IO_PENDING)
// 			{
// 				return FALSE;
// 			}
// 		}
// 	}

}