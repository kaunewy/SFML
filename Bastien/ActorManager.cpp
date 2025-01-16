#include "ActorManager.h"

ActorManager::~ActorManager()
{
	for (Actor* _actor : allActors)
	{
		delete _actor;
	}
}

void ActorManager::BeginPlay()
{
	for (Actor* _actor : allActors)
	{
		_actor->BeginPlay();
	}
}

void ActorManager::Tick(const float _deltaTime)
{
	vector<Actor*> _carbageCollector;

	for (Actor* _actor : allActors)
	{
		_actor->Tick(_deltaTime);
		if (_actor->GetDestroy()) _carbageCollector.push_back(_actor);

	}

	while (!_carbageCollector.empty())
	{
		Actor* _actor = _carbageCollector.back();
		_carbageCollector.pop_back();
		RemoveActor(_actor);
	}

}

void ActorManager::BeginDestroy()
{
	for (Actor* _actor : allActors)
	{
		_actor->BeginDestroy();
	}
}

void ActorManager::RemoveActor(Actor* _actor)
{
	allActors.erase(_actor);
	_actor->BeginDestroy();
	delete _actor;
}
