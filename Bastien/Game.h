#pragma once
#include "Singleton.h"
#include "Random.h"
#include "Actor.h"
#include "BlackHole.h"
#include "ShootingStar.h"


class Game : public Singleton<Game>
{
	RenderWindow window;
	BlackHole* blackHole;

public:
	FORCEINLINE BlackHole* GetBlackHole() const
	{
		return blackHole;
	}

public:
	Game();
	~Game();

private:
	void Start();
	void Update();
	void Stop();
	void CreateBlackHole();
	void CreateRandomActor();
	void DeleteActor(Actor* _actor);
	void ActorInBlackHole(Actor* _actor);

public:
	void UpdateWindow();
	void Launch();
};

