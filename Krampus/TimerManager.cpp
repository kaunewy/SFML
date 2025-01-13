#include "TimerManager.h"

template<class ReturnType, typename ...Args>
Timer<ReturnType, Args...>::Timer(const function<ReturnType(Args...)>& _callback, const Time& _time,
    const bool _startRunning, const bool _isLoop)
{
    isRunning = _startRunning;
    isLoop = _isLoop;
    currentTime = 0.0;
    duration = _time.asMilliseconds();
    callback = _callback;

}
template<class ReturnType, typename ...Args>
void Timer<ReturnType, Args...>::Start()
{
    Reset();
    Resume();
}

template<class ReturnType, typename ...Args>
void Timer<ReturnType, Args...>::Update(const float _deltaTime)
{
    if (!isRunning) return;

    currentTime += _deltaTime;
    if (currentTime >= duration)
    {
        if (callback)
        {
            callback();
        }

        if (!isLoop)
        {
            Stop();
        }

        Reset();
    }
}

template<class ReturnType, typename ...Args>
void Timer<ReturnType, Args...>::Stop()
{
}

template<class ReturnType, typename ...Args>
void Timer<ReturnType, Args...>::Resume()
{
    isRunning = true;
}

template<class ReturnType, typename ...Args>
void Timer<ReturnType, Args...>::Reset()
{
    currentTime = 0.0;
}

template<class ReturnType, typename ...Args>
void Timer<ReturnType, Args...>::Pause()
{
    isRunning = false;
}

template<class ReturnType, typename ...Args>
TimerManager<ReturnType, Args...>::TimerManager()
{
}

template<class ReturnType, typename ...Args>
TimerManager< ReturnType, Args...>::~TimerManager()
{
    for (Timer< ReturnType, Args...>* _timer : allTimers)
    {
        delete _timer;
    }
}

template<class ReturnType, typename ...Args>
void TimerManager< ReturnType, Args...>::Update()
{
    for (Timer< ReturnType, Args...>* _timer : allTimers)
    {

    }
}

template<class ReturnType, typename ...Args>
void TimerManager< ReturnType, Args...>::Pause()
{
    for (Timer< ReturnType, Args...>* _timer : allTimers)
    {
        _timer->Pause();
    }
}