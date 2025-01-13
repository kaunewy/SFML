#pragma once
#include "Singleton.h"


class Game : public Singleton<Game>
{
	RenderWindow window;

public:
	Game();
	~Game();

private:
	void Start();
	void Update();
	void UpdateWindow();
	void Stop();

public:
	void Launch();
};

