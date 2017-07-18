#pragma once

class ActorBase
{
public:
    ActorBase() {}
    virtual ~ActorBase() {}
    virtual bool Initialize() = 0;
    virtual void Finalize() = 0;

};