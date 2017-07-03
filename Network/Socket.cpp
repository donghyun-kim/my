#include "stdafx.h"
#include "Socket.h"

Socket::Socket()
{

}

Socket::~Socket()
{

}

bool Socket::Initialize(Type type)
{
    // 객체의 생성 셋팅이 여러 스레드에서 동시에 이루어 질수 있으니
    // 겍체를 interlock으로 보호해야 한다
    // 까먹지말것

    // tcp
    // SOCK_STREAM

    // udp
    // SOCK_DGRAM

    //listen_socket_ = ::WSASocket(AF_INET, SOCK_STREAM, IPPROTO_IP, NULL, 0, WSA_FLAG_OVERLAPPED);

    return true;
}
