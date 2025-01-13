#include "Game.h"

void Game::LaunchGame()
{
	Map _map;

	_map.InitMap("Assets/Maps/BigMap.txt");
	GameLoop(_map);
}

void Game::GameLoop(Map& _map)
{
	RenderWindow _window;
	_window.create(VideoMode(Vector2u(1920, 1080)), "PacMan");

	unsigned int _pixelCount = 16;

	while (_window.isOpen())
	{
		while (const optional _event = _window.pollEvent())
		{
			if (const Event::KeyPressed* _key = _event->getIf<Event::KeyPressed>())
			{
				if (_key->code == Keyboard::Key::Escape)
				{
					_window.close();
				}
			}
		}
		_window.clear();
		_map.DisplayMap(_window, _pixelCount);
		_window.display();

	}
}
