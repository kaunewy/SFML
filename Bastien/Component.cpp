#include "Component.h"

Component::Component(Actor* _owner)
{
	owner = _owner;
}


void Component::BeginPlay()
{
}

void Component::Tick(const float _deltaTime)
{
}

void Component::BeginDestroy()
{
}