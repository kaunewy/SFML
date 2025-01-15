#pragma once
#include "Component.h"

class ShootingStar : public Component
{

public:
	ShootingStar(Actor* _owner);

public:
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime);

};

