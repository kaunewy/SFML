#pragma once
#include "Singleton.h"

template<class ReturnType, typename ...Args>
class Timer
{
    float currentTime;
    double duration;
    bool isRunning;
    bool isLoop;
    function<ReturnType(Args...)> callback;

public:
    FORCEINLINE bool IsRunning() const
    {
        return isRunning;
    }

    FORCEINLINE bool IsLoop() const
    {
        return isLoop;
    }

    FORCEINLINE double GetCurrentTime() const
    {
        return currentTime;
    }

public:
    Timer(const function<ReturnType(Args...)>& _callback, const Time& _time, const bool _startRunning = false,
        const bool _isLoop = false);

public:
    void Start();
    void Update(const float _deltaTime);
    void Stop();
    void Resume();
    void Reset();
    void Pause();
};

template<class ReturnType, typename ...Args>
class TimerManager : public Singleton<TimerManager< ReturnType, Args...>>
{
    set<Timer<ReturnType, Args...>*> allTimers;

public:
    FORCEINLINE set<Timer< ReturnType, Args...>*> GetAllTimers() const
    {
        return allTimers;
    }

    FORCEINLINE void AddActor(Timer< ReturnType, Args...>* _timer)
    {
        allTimers.insert(_timer);
    }

public:
    TimerManager();
    ~TimerManager();

public:
    void Update();
    void Pause();

private:

};
