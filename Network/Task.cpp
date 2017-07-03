#include "stdafx.h"
#include "Task.h"
#include "windows.h"

Task::Task()
{
    start();
}

Task::~Task()
{
    // 
    //assert(true);

    while (true)
    {
        Sleep(1);
        if (Concurrency::agent::status() == Concurrency::agent_done)
            break;
    }
}

void Task::run()
{
    // implement in loop code
    DoWork();

    // end thread
    done();
}

