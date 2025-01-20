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

	for (Actor* _actor : allActors)
	{
		_actor->Tick(_deltaTime);
		if (_actor->GetDestroy()) carbageCollector.push_back(_actor);
	}

	CarbageCollector();

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

void ActorManager::CarbageCollector()
{
	while (!carbageCollector.empty())
	{
		Actor* _actor = carbageCollector.back();
		carbageCollector.pop_back();
		RemoveActor(_actor);
	}
}

void ActorManager::RemoveAllActor()
{

	for (Actor* _actor : allActors)
	{
		if(_actor->GetComponent<ShootingStar>() != nullptr)
		{
			carbageCollector.push_back(_actor);
		}
	}

	CarbageCollector();
}
