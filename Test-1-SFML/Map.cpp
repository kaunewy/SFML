#include "Map.h"

void Map::InitMap(string _level)
{
	ifstream _readStream = ifstream(_level, ios_base::in);
	_readStream.seekg(0, ios::beg);
    string _line;
	while (getline(_readStream, _line))
	{
        map.push_back(vector<char>());
        for (char _char : _line)
        {
            map.back().push_back(_char);
        }
	}
}

void Map::DisplayMap(RenderWindow& _window, unsigned int _pixelCount)
{
	for (unsigned int _i = 0; _i < map.size(); _i++)
	{
		for (unsigned int _j = 0; _j < map[0].size(); _j++)
		{
			RectangleShape _rect = RectangleShape(Vector2f(float(_pixelCount), float(_pixelCount)));
			const string _whichElement = "Assets/Textures/" + ConvertCharToTexture(map[_i][_j], _i, _j);
			Texture _texture = Texture(_whichElement);
			_rect.setTexture(&_texture);
			_rect.setPosition(Vector2f(float(_j * _pixelCount), float(_i * _pixelCount)));
			_window.draw(_rect);
		}
	}
}

string Map::ConvertCharToTexture(const char _char, const unsigned int _x, const unsigned int _y)
{
	switch (_char)
	{
	case '#':
		if (_x == 0)
		{
			if (_y == 0)
			{
				return "Walls/Wall_AngleTopLeft.png";
			}
			else if (_y == map[0].size() - 1)
			{
				return "Walls/Wall_AngleTopRight.png";
			}
			return "Walls/Wall_Top.png";
		}
		else if (_x == map.size() - 1)
		{
			if (_y == 0)
			{
				return "Walls/Wall_AngleBottomLeft.png";
			}
			else if (_y == map[0].size() - 1)
			{
				return "Walls/Wall_AngleBottomRight.png";
			}
			return "Walls/Wall_Bottom.png";
		}
		else if (_y == 0)
		{
			return "Walls/Wall_Left.png";
		}
		else
		{
			return "Walls/Wall_Right.png";
		}
		break;
	case '*':
		return "Foods/Apple.png";
		break;
	default:
		return "Foods/Point.png";
		break;
	}
}
