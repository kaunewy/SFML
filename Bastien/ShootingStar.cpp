#include "ShootingStar.h"
#include "Random.h"
#include "Game.h"
#include "ActorManager.h"

ShootingStar::ShootingStar(Actor* _owner) : Component(_owner)
{
	rotationFactor = Angle(degrees(GetRandomNumberInRange(0, 259)));
	currentDirection = {1.f, 1.f };
	increment = degrees(0.1f);
}

void ShootingStar::BeginPlay()
{
	owner->GetShape()->GetDrawable()->setOrigin({260.f, 300.f});
}

void ShootingStar::Tick(const float _deltaTime)
{
	FloatRect _shootingStarBounds = owner->GetShape()->GetDrawable()->getGlobalBounds();
	FloatRect _targetBound = Game::GetInstance().GetBlackHole()->GetBlackHole()->GetShape()->GetDrawable()->getGlobalBounds();
	if (_shootingStarBounds.findIntersection(_targetBound))
	{
		owner->SetDestroyTrue();
		return;
	}
	else
	{
		CheckStarsCollions();

		Vector2f _scale = owner->GetShape()->GetDrawable()->getScale();
		_scale.x -= 0.1f * _deltaTime;
		_scale.y -= 0.1f * _deltaTime;
		owner->GetShape()->SetScale(_scale);
		owner->GetShape()->SetPosition({ owner->GetShape()->GetPosition().x + 1 * _deltaTime * 10, owner->GetShape()->GetPosition().y + 1 * _deltaTime * 10 });
		owner->GetShape()->SetRotation(rotationFactor += increment);
	}
	
}

void ShootingStar::CheckStarsCollions()
{
	FloatRect _currentShootingStarBounds = this->owner->GetShape()->GetDrawable()->getGlobalBounds();

	for (Actor* _actor : ActorManager::GetInstance().GetAllActors())
	{
		if (_actor->GetComponent<ShootingStar>())
		{
			FloatRect _otherShootingStarBounds = _actor->GetShape()->GetDrawable()->getGlobalBounds();

			if (_currentShootingStarBounds.findIntersection(_otherShootingStarBounds))
			{
				increment = increment * -1;
			}
		}
	}
}

