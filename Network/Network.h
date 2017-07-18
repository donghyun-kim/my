#pragma once
#include "Proactor.h"
#include "Listener.h"

class ActorBase;
class SocketBase;

class Network
{
public:
    Network(const WCHAR * ip_addres, unsigned short port);
    ~Network();

private:
    ActorBase* actor_;
    SocketBase* socket_;
};