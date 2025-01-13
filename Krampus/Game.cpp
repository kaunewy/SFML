#include "Game.h"
#include "ActorManager.h"

Game::Game()
{
	window = RenderWindow();
	Actor* shape;
	shape = new Actor(20.0f, "DefaultTexture");
}

Game::~Game()
{
}

void Game::UpdateWindow()
{
	window.clear();
	for (Actor* _actor : ActorManager::GetInstance().GetAllActors())
	{
		window.draw(*_actor->GetShape()->GetDrawable());
	}
	//window.draw(*_shape->GetDrawable());
	window.display();
}

void Game::Start()
{
	RenderWindow _mainWindow;
	_mainWindow.create(VideoMode(Vector2u(500, 500)), "", State::Windowed);

}

void Game::Update()
{
	while (window.isOpen())
	{
		while (const optional _event = window.pollEvent())
		{
			if (_event->is<Event::Closed>())
			{
				window.close();
			}
		}

		UpdateWindow();
	}
}

void Game::Stop()
{
}

void Game::Launch()
{
	Start();
	Update();
	Stop();
}
