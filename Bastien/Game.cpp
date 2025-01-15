#include "Game.h"
#include "ActorManager.h"
#include "TimerManager.h"

Game::Game()
{
	window = RenderWindow();

	Actor* _background = new Actor({ 500, 500 }, "BackGround");
	_background->GetShape()->SetPosition({ 250.f, 250.f });

}

Game::~Game()
{
	delete blackHole;
}

void Game::UpdateWindow()
{
	window.clear();
	for (Actor* _actor : ActorManager::GetInstance().GetAllActors())
	{
		window.draw(*_actor->GetShape()->GetDrawable());
	}
	window.display();
}

void Game::Start()
{
	window.create(VideoMode(Vector2u(500, 500)), "Test", State::Windowed);
	CreateBlackHole();
	CreateRandomActor();
	ActorManager::GetInstance().BeginPlay();
}

void Game::Update()
{
	while (window.isOpen())
	{
		TM_Seconds& _timer = TM_Seconds::GetInstance();
		_timer.Update();
		while (const optional _event = window.pollEvent())
		{
			if (_event->is<Event::Closed>())
			{
				window.close();
			}
		}
		const float _deltaTime = _timer.GetDeltaTime().asSeconds() + 0.0000001f;
		ActorManager::GetInstance().Tick(_deltaTime);

		UpdateWindow();
	}
}

void Game::Stop()
{
}


void Game::CreateBlackHole()
{
	blackHole = new BlackHole();
}



void Game::CreateRandomActor()
{
	int _test = 0;
	for (unsigned int _i = 0; _i < 100; _i++)
	{
		int _value = GetRandomNumberInRange(0, 2);
		Vector2f _size = { float(GetRandomNumberInRange(5, 30)) ,float(GetRandomNumberInRange(5, 30)) };
		Actor* _shape;
		if (_value == 0)_shape = new Actor(_size.x, "Star");
		else if(_value == 1) _shape = new Actor({ _size.x,_size.y }, "Star");
		else
		{
			_shape = new Actor(_size.x, "Star", IntRect(), 3);
		}

		_shape->GetShape()->SetPosition({ float(GetRandomNumberInRange(0,500)),float(GetRandomNumberInRange(0,500)) });
		//_shape->GetShape()->SetOrigin(blackHole->GetBlackHole()->GetShape()->GetPosition());
		_shape->AddComponent(new ShootingStar(_shape));
	}
}

void Game::DeleteActor(Actor* _actor)
{
	ActorManager::GetInstance().GetAllActors().erase(_actor);
}

void Game::ActorInBlackHole(Actor* _actor)
{
	
}

void Game::Launch()
{
	Start();
	Update();
	Stop();
}
