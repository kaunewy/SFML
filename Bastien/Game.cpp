#include "Game.h"
#include "ActorManager.h"
#include "TimerManager.h"

Game::Game()
{
	window = RenderWindow();
}

Game::~Game()
{
	delete blackHole;
}

void Game::UpdateWindow()
{
	window.clear();
	BackGround();
	window.draw(*blackHole->GetBlackHole()->GetShape()->GetDrawable());
	DisplayActor();
	window.display();
}

void Game::Start()
{
	window.create(VideoMode(Vector2u(500, 500)), "Test", State::Windowed);
	CreateBlackHole();
	CreateRandomActor();
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
		const float _deltaTime = _timer.GetDeltaTime().asSeconds();
		ActorManager::GetInstance().Tick(_deltaTime + 0.0001f);

		UpdateWindow();
	}
}

void Game::Stop()
{
}

void Game::BackGround()
{
	RectangleShape _rectBG = RectangleShape({ 500,500 });
	Texture _backGround = Texture("Assets/Textures/BackGround.png");
	_rectBG.setTexture(&_backGround);
	window.draw(_rectBG);
}

void Game::CreateBlackHole()
{
	blackHole = new BlackHole();
}

void Game::DisplayActor()
{
	for (Actor* _actor : ActorManager::GetInstance().GetAllActors())
	{
		MoveActor(_actor);

		window.draw(*_actor->GetShape()->GetDrawable());
	}
}

void Game::MoveActor(Actor* _actor)
{
	static float _degrees = 0;
	_actor->GetShape()->SetRotation(degrees(_degrees += 0.01f));
	Vector2f _currentPosition = { _actor->GetShape()->GetPosition().x, _actor->GetShape()->GetPosition().y };
	_actor->GetShape()->SetScale({1.5f,1.5f});
	_actor->GetShape()->SetPosition({ _currentPosition.x + 0.3f, _currentPosition.y + 0.3f });
}

void Game::CreateRandomActor()
{
	int _test = 0;
	for (unsigned int _i = 0; _i < 100; _i++)
	{
		int _value = GetRandomNumberInRange(0, 2);
		Vector2f _size = { float(GetRandomNumberInRange(5, 30)) ,float(GetRandomNumberInRange(5, 30)) };
		Actor* _shape;
		if (_value == 0)_shape = new Actor(_size.x);
		else if(_value == 1) _shape = new Actor({ _size.x,_size.y });
		else
		{
			_shape = new Actor(_size.x, "", IntRect(), 3);
		}
		
		cout << _test++ << endl;

		_shape->GetShape()->SetPosition({ float(GetRandomNumberInRange(0,500)),float(GetRandomNumberInRange(0,500)) });
		_shape->GetShape()->SetOrigin(blackHole->GetBlackHole()->GetShape()->GetPosition());
		ActorManager::GetInstance().AddActor(_shape);
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
