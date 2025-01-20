#pragma once
#include "Component.h"

class ShootingStar : public Component
{
	Angle rotationFactor;
	Vector2f currentDirection;
	Angle increment;

public:
	ShootingStar(Actor* _owner);

public:
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime);
	void CheckStarsCollions();
};

