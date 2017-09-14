#pragma once

#include <thread>

class Task
{
public:
    Task();
    virtual ~Task();

    virtual void Start();
    virtual void Stop();

    virtual void DoWork() = 0;

    bool IsWork() { return loop_state_; }
private:
    bool loop_state_;
    std::thread* thread_;
};