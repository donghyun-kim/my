#include "stdafx.h"
#include "Log.h"

Log::Log() : _impl(nullptr)
{

}

Log::~Log()
{
    if (_impl)
        delete _impl;
}

bool Log::Initialize()
{
    _impl = new LogImplGlog;
    
    if (_impl && _impl->Initialize() == false)
        return false;

    return true;
}

void Log::Write(Type type, WCHAR * log_string)
{
    _impl->Write(log_string);
}
