#include "ShootingStar.h"
#include "Actor.h"

ShootingStar::ShootingStar(Actor* _owner) : Component(_owner)
{
}

void ShootingStar::BeginPlay()
{
	owner->GetShape()->GetDrawable()->setOrigin({260.f, 300.f});
}

void ShootingStar::Tick(const float _deltaTime)
{
	Vector2f _currentDirection = { 1.f, 1.f };
	Vector2f _scale = owner->GetShape()->GetDrawable()->getScale();
	static Angle _rotation = degrees(0.f);
	_scale.x -= 0.1f * _deltaTime;
	_scale.y -= 0.1f * _deltaTime;
	//owner->GetShape()->SetScale(_scale);
	//owner->GetShape()->SetPosition({ owner->GetShape()->GetPosition().x + 1 * _deltaTime * 100, owner->GetShape()->GetPosition().y + 1 * _deltaTime * 100} );
	owner->GetShape()->SetRotation(_rotation += degrees(0.001));
}
