#include "ShootingStar.h"
#include "Actor.h"
#include "Random.h"
#include "ActorManager.h"

ShootingStar::ShootingStar(Actor* _owner) : Component(_owner)
{
	rotationFactor = Angle(degrees(GetRandomNumberInRange(0, 259)));

}

void ShootingStar::BeginPlay()
{
	owner->GetShape()->GetDrawable()->setOrigin({260.f, 300.f});
}

void ShootingStar::Tick(const float _deltaTime)
{
	FloatRect _shootingStarBounds = owner->GetShape()->GetDrawable()->getGlobalBounds();
	FloatRect _targetBound(Vector2f(260.f - 90.f, 300.f - 90.f), Vector2f{ 90.f,90.f });
	if (_shootingStarBounds.findIntersection(_targetBound))
	{
		owner->SetDestroyTrue();
		return;
	}
	else
	{
		Vector2f _currentDirection = { 1.f, 1.f };
		Vector2f _scale = owner->GetShape()->GetDrawable()->getScale();
		_scale.x -= 0.1f * _deltaTime;
		_scale.y -= 0.1f * _deltaTime;
		//owner->GetShape()->SetScale(_scale);
		owner->GetShape()->SetPosition({ owner->GetShape()->GetPosition().x + 1 * _deltaTime * 10, owner->GetShape()->GetPosition().y + 1 * _deltaTime * 10 });
		owner->GetShape()->SetRotation(rotationFactor += degrees(0.1));
	}
	
}

