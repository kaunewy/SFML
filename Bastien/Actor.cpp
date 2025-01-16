#include "Actor.h"
#include "ActorManager.h"
#include "TextureManager.h"


Actor::Actor()
{
}

Actor::Actor(const float _radius, const string& _path, const IntRect& _rect, const size_t& _pointCount)
{
	shouldBeDestroy = false;
	shape = new ShapeObject(_radius, _path,_rect, _pointCount);
	shape->SetOrigin({ _radius, _radius });
	TextureManager::GetInstance().Load(shape, _path, _rect);
	Register();
}

Actor::Actor(const Vector2f& _size, const string& _path, const IntRect& _rect)
{
	shouldBeDestroy = false;
	shape = new ShapeObject(_size);
	shape->SetOrigin(_size / 2.f);
	TextureManager::GetInstance().Load(shape, _path, _rect);
	Register();
}

Actor::~Actor()
{
	for (Component* _component : components)
	{
		delete _component;
	}
}

void Actor::BeginPlay()
{
	for (Component* _component : components)
	{
		_component->BeginPlay();
	}
}

void Actor::Tick(const float _deltaTime)
{
	
	for (Component* _component : components)
	{
		_component->Tick(_deltaTime);
	}
}

void Actor::BeginDestroy()
{
	for (Component* _component : components)
	{
		_component->BeginDestroy();
	}
}

void Actor::AddComponent(Component* _component)
{
	//if(GetComponent<decltype(_component)>()) return;
	components.insert(_component);
}

void Actor::RemoveComponent(Component* _component)
{
	components.erase(_component);
}



void Actor::Register()
{
	ActorManager::GetInstance().AddActor(this);
}