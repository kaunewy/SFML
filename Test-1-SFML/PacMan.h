#pragma once
#include "Coordinate.h"

class PacMan
{
	Coord _pos;

public:
	void DisplayPacMan(RenderWindow& _window);
	void MovePacMan();
};

