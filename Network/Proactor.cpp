#include "stdafx.h"
#include "Proactor.h"
#include "EventHandler.h"

Proactor::Proactor() : loop_state_(false), iocp_handle_(INVALID_HANDLE_VALUE), spwan_thread_(0)
{
    
}

Proactor::~Proactor()
{

}

bool Proactor::Initialize()
{
    spwan_thread_ = 4;
    iocp_handle_ = CreateIoCompletionPort(INVALID_HANDLE_VALUE, nullptr, 0, spwan_thread_);

    if (iocp_handle_ == nullptr)
        return false;
    
    loop_state_ = true;

    // n개 이상으로 process 를 만들도록 한다

    processors_.reserve(spwan_thread_);

    for (DWORD count = 0; count < spwan_thread_; ++count)
    {
        processors_[count] = new Processor(loop_state_, iocp_handle_); 
    }

    return true;
}

void Proactor::Finalize()
{
    if (iocp_handle_)
    {
        CloseHandle(iocp_handle_);
        iocp_handle_ = INVALID_HANDLE_VALUE;
    }

    for each (Processor* process in processors_)
    {
        delete process;
    }

    processors_.clear();
}

bool Proactor::Register(HANDLE handle)
{
    HANDLE result_handle = CreateIoCompletionPort(handle, iocp_handle_, (ULONG_PTR)nullptr, spwan_thread_);
     if (result_handle == INVALID_HANDLE_VALUE)
         return false;

    if (result_handle == nullptr && GetLastError() != ERROR_INVALID_PARAMETER)
        return false;
 
     return true;
}

Proactor::Processor::Processor(bool& loop_state, HANDLE& proactor_handle) : loop_state_(loop_state), proactor_handle_(proactor_handle)
{
}

Proactor::Processor::~Processor()
{

}

void Proactor::Processor::DoWork()
{
    BOOL result = FALSE;
    DWORD number_of_bytes_transferred = 0;
    PULONG_PTR completion_key = nullptr;
    LPOVERLAPPED* overlapped = nullptr;

    while (loop_state_)
    {
        // 완료된 io만을 알 수있음
        result = GetQueuedCompletionStatus(proactor_handle_, &number_of_bytes_transferred, completion_key, overlapped, INFINITE);

        if (completion_key == nullptr)
            break;

        if (overlapped == nullptr)
        {
            // overlapped object null
            continue;
        }

        EventHandler* event_handler = (EventHandler*)completion_key;

        if (result == FALSE)
        {
            // cast overlapped
            //event_handler->Success(number_of_bytes_transferred, overlapped);
        }
        else
        {
            event_handler->Failed(0);
        }
    }

    done();
}