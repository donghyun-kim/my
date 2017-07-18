#pragma once

class EventHandler
{
public:
    EventHandler();
    ~EventHandler();

    virtual void Success(DWORD bytes_transferred) = 0;
    virtual void Failed(DWORD error) = 0;
};

class OverlappedEventHandler : public OVERLAPPED, EventHandler
{
public:
    OverlappedEventHandler();

};

class PollingEventHandler : public EventHandler
{
public:
    

};
