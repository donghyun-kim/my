#pragma once

template <typename T>
class Singletone
{
public:
    Singletone() {}
    
    ~Singletone() {}

    static T* Getinstance() { 
        static T obj;
        return &obj;
    }
};