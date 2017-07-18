#pragma once
#include "SocketBase.h"
#include "Proactor.h"

class Actor;

class OverlapdSocketBase : public SocketBase
{
public:
    OverlapdSocketBase(ActorBase& actor);
    virtual ~OverlapdSocketBase() {};

    virtual bool Initialize() override;

    virtual bool Send() override;
    virtual bool Recv() override;

private:
    friend class AcceptAction;

    enum ActionType
    {
        ActionAccept,
        ActionSend,
        ActionRecv,
        ActionDisconnect,
        ActionEnd,
    };

    class OverlappedAction;
    OverlappedAction* action_[ActionEnd];

    SOCKET socket_;
    SOCKET listen_socket_;

    Proactor& proactor_;
};

