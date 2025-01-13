#pragma once
#include "Map.h"

class Game
{
	Map _map;

public:
	Game() = default;

public:
	void LaunchGame();

private:
	void GameLoop(Map& _map);
};

