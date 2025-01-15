#pragma once
#include "Singleton.h"
#include "Random.h"
#include "Actor.h"
#include "BlackHole.h"


class Game : public Singleton<Game>
{
	RenderWindow window;
	BlackHole* blackHole;

public:
	Game();
	~Game();

private:
	void Start();
	void Update();
	void Stop();
	void BackGround();
	void CreateBlackHole();
	void DisplayActor();
	void MoveActor(Actor* _actor);
	void CreateRandomActor();
	void DeleteActor(Actor* _actor);
	void ActorInBlackHole(Actor* _actor);

public:
	void UpdateWindow();
	void Launch();
};

