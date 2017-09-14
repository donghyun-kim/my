#pragma once

#include <set>

template <typename T>
class Broadcaster
{
public:
    Broadcaster(T intput) : val(intput) {}
    T& Get() { return val; }
private:
    T val;
};

class Observer;

class Publisher
{
public:
    Publisher() {}

    template <typename T>
    void Publisher::Broadcast(Broadcaster<T>& context) {
        Update(context);
    }

    bool Subscription(Observer& observer) {
        _observers.insert(&observer);
        return true;
    }

    bool Unsubscription(Observer& observer) {
        _observers.erase(&observer);
        return true;
    }

private:
    template <typename T>
    void Publisher::Update(Broadcaster<T>& context) {
        for each (Observer* observer in _observers) {
            observer->BroadCasting(*this, context);
        }
    }

    typedef std::set<Observer*> Observers;
    Observers _observers;
};

class Observer
{
public:
    Observer() {}

    template <typename T>
    void Observer::BroadCasting(Publisher& publiser, Broadcaster<T>& context){}
};