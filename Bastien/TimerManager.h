#pragma once
#include "Singleton.h"
#include "Game.h"

using Seconds = float;
using MilliSec = int32_t;
using MicroSec = int64_t;

template <typename DurationType>
class Timer;

template <typename DurationType = MilliSec>
class TimerManager : public Singleton<TimerManager<DurationType>>
{

	using T = Timer<DurationType>;
	friend T;

	// Objet qui contient toutes les données de temps
	Clock clock;
	// Temps en miliseconde depuis le début du prog
	DurationType time;
	// Stocke temporairement la précédente durée de la frame
	DurationType lastTime;
	// Mettre à jours le content de FPS
	DurationType lastFrameTime;
	// Temps depuis la dernière image rendu 
	DurationType elapsedTime;
	// Temps depuis la dernière image rendu avec le timeScale
	DurationType deltaTime;
	// Vitesse à laquelle le temps s'écoule
	DurationType timeScale;
	// NB image rendu depuis le début
	long long framesCount;
	// MAximum d'image rendu par seconde
	unsigned short maxFrameRate;
	// Nombre d'image rendu par seconde
	DurationType fps;
	// Collection de tous les time existant
	set<T*> allTimers;

	map<type_index, DurationType> durations;

private:
	FORCEINLINE DurationType GetDuration() const
	{
		return durations.at(typeid(DurationType));
	}

public:
	FORCEINLINE set<T*> GetAllTimers() const
	{
		return allTimers;
	}

	FORCEINLINE void AddTimer(T* _timer)
	{
		allTimers.insert(_timer);
	}

	FORCEINLINE void SetTimerScale(const DurationType& _timeScale)
	{
		timeScale = _timeScale;
	}
	FORCEINLINE DurationType ComputeFPS() const
	{
		return GetDuration() / (time - lastFrameTime);
	}

	FORCEINLINE Time GetDeltaTime()const
	{
		return Time(seconds(deltaTime * GetDuration()));
	}

public:
	TimerManager()
	{
		clock = Clock();
		time = DurationType();
		lastTime = DurationType();
		lastFrameTime = DurationType();
		elapsedTime = DurationType();
		deltaTime = DurationType();
		timeScale = DurationType();
		framesCount = 0;
		maxFrameRate = 50;
		fps = DurationType();
		allTimers = set<T*>();

		durations =
		{
			{typeid(Seconds), 1},
			{typeid(MilliSec), 1000},
			{typeid(MicroSec), 1000000},
		};
	}
	~TimerManager()
	{
		for (T* _timer : allTimers)
		{
			delete _timer;
		}
	}

public:
	void Update()
	{
		lastTime = time;

		time = GetTime(clock.getElapsedTime());
		elapsedTime = time - lastTime;
		framesCount++;

		if (lastFrameTime == 0 || time - lastFrameTime >= maxFrameRate)
		{
			lastFrameTime = time;
			Game::GetInstance().UpdateWindow();
		}

		for (T* _timer : allTimers)
		{
			_timer->Update(deltaTime);
		}
	}
	void Pause()
	{
		for (T* _timer : allTimers)
		{
			_timer->Pause();
		}
	}

private:
	FORCEINLINE DurationType GetTime(const Time& _time) const
	{
		map<type_index, function<DurationType()>> _durationCallback =
		{
			{typeid(Seconds), [&]() { return _time.asSeconds(); }},
			{typeid(MilliSec), [&]() { return _time.asMilliseconds(); }},
			{typeid(MicroSec), [&]() { return _time.asMicroseconds(); }}

		};
		return _durationCallback[typeid(DurationType)]();
	}

};

using TM_Seconds = TimerManager<Seconds>;
using TM_Milli = TimerManager<MilliSec>;
using TM_Micro = TimerManager<MicroSec>;

template <typename DurationType = MilliSec>
class Timer
{
	DurationType currentTime;
	DurationType duration;
	bool isRunning;
	bool isLoop;
	function<void()> callback;

public:
	FORCEINLINE bool IsRunning() const
	{
		return isRunning;
	}

	FORCEINLINE bool IsLoop() const
	{
		return isLoop;
	}

	FORCEINLINE DurationType GetCurrentTime() const
	{
		return currentTime;
	}

public:
	Timer(const function<void()>& _callback, const Time& _time, const bool _startRunning = false,
		const bool _isLoop = false)
	{
		isRunning = _startRunning;
		isLoop = _isLoop;
		currentTime = 0.0;
		duration = TimerManager<DurationType>::GetInstance().GetTime(_time);
		callback = _callback;
		TimerManager<DurationType>::GetInstance().AddTimer(this);
	}

public:
	void Start()
	{
		Reset();
		Resume();
	}
	void Update(const float _deltaTime)
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
	void Stop()
	{
	}
	void Resume()
	{
		isRunning = true;
	}
	void Reset()
	{
		currentTime = 0.0;
	}
	void Pause()
	{
		isRunning = false;
	}

};