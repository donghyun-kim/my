#pragma once
#include <agents.h>

class Task : public Concurrency::agent
{
public:
    Task();
    virtual ~Task();

    virtual void DoWork() = 0;

private:
    void run() override;
};