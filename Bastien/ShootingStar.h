#pragma once
#include "Component.h"

class ShootingStar : public Component
{
	Angle rotationFactor;

public:
	ShootingStar(Actor* _owner);

public:
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime);
};

