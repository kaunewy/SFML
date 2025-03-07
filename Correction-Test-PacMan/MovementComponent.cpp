#include "MovementComponent.h"

MovementComponent::MovementComponent(Entity* _owner) : Component(_owner)
{
	speed = 6;
}

void MovementComponent::Move(const Vector2i& _direction)
{
	owner->GetShape().move(Vector2f(_direction * speed));
}