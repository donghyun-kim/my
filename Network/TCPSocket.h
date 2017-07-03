#pragma once

class Actor;

class TCPSocket 
{
public:
    TCPSocket(Actor& proactor);
    virtual ~TCPSocket();

    bool Init();

    bool Send();
    bool Recv();

private:
    friend class TCPSocketAccept;

    enum ActionType
    {
        ActionAccept,
        ActionSend,
        ActionRecv,
        ActionDisconnect,
        ActionEnd,
    };

    class Action;
    Action* action_[ActionEnd];

    Proactor& proactor_;
    SOCKET socket_;
    SOCKET listen_socket_;
};

