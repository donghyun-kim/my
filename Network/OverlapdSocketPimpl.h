#pragma once

#include "OverlapdSocket.h"
#include "Proactor.h"
#include "EventHandler.h"

#define BUFSIZE 8192

class OverlapdSocketBase::OverlappedAction : public OverlappedEventHandler
{
public:
    OverlappedAction(OverlapdSocketBase& socket, Proactor& proactor) : base_(socket) {}
    virtual ~OverlappedAction() {}

private:
    friend class AcceptAction;

    OverlapdSocketBase base_;
};

class AcceptAction : public OverlapdSocketBase::OverlappedAction
{
public:
    AcceptAction(OverlapdSocketBase& socket, Proactor& proactor);
    virtual ~AcceptAction();

    bool init();

    virtual void Success(DWORD bytes_transferred);
    virtual void Failed(DWORD error);

private:
    char buffer_[BUFSIZE];
};
