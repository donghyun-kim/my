#include "stdafx.h"
#include "EventHandler.h"

EventHandler::EventHandler()
{

}

EventHandler::~EventHandler()
{

}

OverlappedEventHandler::OverlappedEventHandler()
{
    hEvent = nullptr;
    Internal = 0;
    InternalHigh = 0;
    Offset = 0;
    OffsetHigh = 0;
}
