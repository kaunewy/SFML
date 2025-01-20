#pragma once
#include "Core.h"

class Actor;

class Component : public Core
{

protected:
	Actor* owner;

public:
	Component(Actor* _owner);
	virtual ~Component() {};
public:

	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestroy() override;

};

