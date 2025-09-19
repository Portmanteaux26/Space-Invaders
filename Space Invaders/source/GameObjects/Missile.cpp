#include "GameConstants.h"
#include "Missile.h"
#include "ResourceManager.h"


Missile::Missile()
	: GameObject()
	, AnimSprites(4)
{
	AnimSprites[0] = &ResourceManager::GetTexture("plunger_0");
	AnimSprites[1] = &ResourceManager::GetTexture("plunger_1");
	AnimSprites[2] = &ResourceManager::GetTexture("plunger_2");
	AnimSprites[3] = &ResourceManager::GetTexture("plunger_3");
	Sprite = AnimSprites[0];
	Size = glm::vec2(Sprite->Width, Sprite->Height);
	mState = GameObject::State::Destroyed;
	CollisionID = ColMaskMissile;
	CanCollideWith = CollisionMask(ColMaskCannon | ColMaskLaser | ColMaskBunker);
}

void Missile::DoCollision(const GameObject* partner)
{
	if (partner->CollisionID & ColMaskLaser)
	{
		mState = GameObject::State::Exploding;
		Sprite = &ResourceManager::GetTexture("missile_explosion");
	}
	else
	{
		mState = GameObject::State::Destroyed;
	}
}

void Missile::Update(float dt)
{
	if (mState == GameObject::State::Exploding)
	{
		if (ExplosionTimer > 0.2f)
		{
			mState = GameObject::State::Destroyed;
			Sprite = AnimSprites[0];
			ExplosionTimer = 0.0f;
		}
		else
		{
			ExplosionTimer += dt;
		}
	}

	else if (mState == GameObject::State::Active)
	{
		Position.y += VelocityY * dt;
		if (Position.y + Size.y >= GameConstants::PlayableY)
		{
			mState = GameObject::State::Exploding;
			this->Sprite = &ResourceManager::GetTexture("missile_explosion");
		}
		else
		{
			AnimCycle(dt);
		}
	}
}

void Missile::Shoot(const GameObject* shooter)
{
	if (mState == GameObject::State::Destroyed)
	{
		mState = GameObject::State::Active;
		this->Position.x = shooter->Position.x + shooter->Size.x / 2.0f - this->Size.x / 2.0f;
		this->Position.y = shooter->Position.y + this->Size.y;
	}
}

void Missile::AnimCycle(float dt)
{
	if (AnimTimer > 0.2f)
	{
		AnimIndex = (AnimIndex + 1) % AnimSprites.size();
		Sprite = AnimSprites[AnimIndex];
		AnimTimer = 0.0f;
	}
	else
	{
		AnimTimer += dt;
	}
}