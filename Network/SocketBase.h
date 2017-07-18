#pragma once

class ActorBase;

class SocketBase
{
public:
    enum Type
    {
        TCP,
        UDP,
    };

    SocketBase(ActorBase& actor) {}
    virtual ~SocketBase() {}

    virtual bool Initialize() = 0;

    virtual bool Send() = 0;
    virtual bool Recv() = 0;

private:
    Type type_;
};