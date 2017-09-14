#include "stdafx.h"
#include "Task.h"
#include "windows.h"


void run(Task* task)
{
    // implement in loop code
    while (task->IsWork())
    {
        task->DoWork();
    }

    // end thread
}

Task::Task() : loop_state_(false)
{
}

Task::~Task()
{
    Stop();
}

void Task::Start()
{
    loop_state_ = true;
    thread_ = new std::thread(&run, this);
}

void Task::Stop()
{
    loop_state_ = false;
    delete thread_;
}