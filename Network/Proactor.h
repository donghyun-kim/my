#pragma once
#include "ActorBase.h"
#include "Task.h"

class Proactor : public ActorBase
{
public:
    Proactor();
    virtual ~Proactor() override;

    virtual bool Initialize() override;
    virtual void Finalize() override;

    bool Register(HANDLE handle);

private:
    class Processor : Task
    {
    public:
        Processor(bool& loop_state, HANDLE& proactor_handle);
        virtual ~Processor();

    private:
        virtual void DoWork() override;

        bool loop_state_;
        HANDLE& proactor_handle_;
    };

    bool loop_state_;
    HANDLE iocp_handle_;
    DWORD spwan_thread_;
    std::vector<Processor*> processors_;
};