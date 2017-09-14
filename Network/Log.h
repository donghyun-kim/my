#pragma once
#include "SingletonePattern.h"
class LogImplGlog;

class Log : public Singletone<Log>
{
public:
    Log();
    ~Log();

    bool Initialize();
    
    enum Type
    {
        Notice,
        Warning,
        Fatal,
    };

    void Write(Type type, WCHAR * log_string);

private:
    class Impl
    {
    public:
        virtual bool Initialize() = 0;
        virtual bool Write(WCHAR * log_string) = 0;
    };

    friend LogImplGlog;
    Impl* _impl;
};

/////////////////////////////////////////////////////////////////////////////////////////////

class LogImplGlog : public Log::Impl
{
public:
    LogImplGlog(){}
    ~LogImplGlog(){}

    virtual bool Initialize();
    virtual bool Write(WCHAR * log_string);
};