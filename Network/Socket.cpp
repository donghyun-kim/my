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
    // ��ü�� ���� ������ ���� �����忡�� ���ÿ� �̷�� ���� ������
    // ��ü�� interlock���� ��ȣ�ؾ� �Ѵ�
    // ���������

    // tcp
    // SOCK_STREAM

    // udp
    // SOCK_DGRAM

    //listen_socket_ = ::WSASocket(AF_INET, SOCK_STREAM, IPPROTO_IP, NULL, 0, WSA_FLAG_OVERLAPPED);

    return true;
}
