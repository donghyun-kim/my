#pragma once
#include "Proactor.h"
#include "Listener.h"

class Proactor;
class TCPSocket;

class Network
{
public:
    Network(const WCHAR * ip_addres, unsigned short port);
    ~Network();

private:
    Proactor* proactor_;
    TCPSocket* tcp_socket_;
};