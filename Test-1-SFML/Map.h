#pragma once
#include "Macro.h"
#include <vector>
#include <fstream>


enum TileType
{
	WALL,
	GUM,
	PACMAN,
	GHOST,

	COUNT,
};

class Map
{
	vector<vector<char>> map;
	string currentLevel;

public:
	inline vector<vector<char>> GetMap() const
	{
		return map;
	}

	inline string GetCurrentLevel() const
	{
		return currentLevel;
	}

public:
	Map() = default;

public:
	void InitMap(string _level);
	void DisplayMap(RenderWindow& _window, unsigned int _pixelCount);
	string ConvertCharToTexture(const char _char, const unsigned int _x, const unsigned int _y);
	
};

