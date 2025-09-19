#include "Invader.h"
#include "InvaderController.h"
#include "Missile.h"
#include "ResourceManager.h"


Invader::Invader(Species _species, glm::vec2 _position)
	: GameObject()
	, mSpecies(_species)
	, pMissile(nullptr)
{
	if (mSpecies == Invader::Species::Squid)
	{
		Sprite = &ResourceManager::GetTexture("squid_down");
	}
	else if (mSpecies == Invader::Species::Crab)
	{
		Sprite = &ResourceManager::GetTexture("crab_down");
	}
	else
	{
		Sprite = &ResourceManager::GetTexture("octopus_down");
	}

	Size = glm::vec2(Sprite->Width, Sprite->Height);
	Position = _position;
	CollisionID = ColMaskInvader;
	CanCollideWith = ColMaskLaser;
}

void Invader::DoCollision(const GameObject* partner)
{
	this->mState = GameObject::State::Exploding;
	float AlienWidth = Size.x;
	this->Sprite = &ResourceManager::GetTexture("invader_explosion");
	// adjust size and position to center explosion sprite
	Size = glm::vec2(Sprite->Width, Sprite->Height);
	Position.x -= (Size.x - AlienWidth) / 2;
}

void Invader::Update(float dt)
{
	if (mState == GameObject::State::Exploding)
	{
		if (ExplosionTimer > 0.2f)
		{
			mState = GameObject::State::Destroyed;
			ExplosionTimer = 0.0f;
		}
		else
		{
			ExplosionTimer += dt;
		}
	}

	else if (mState == GameObject::State::Active)
	{
		if (InvaderController::MovementState == InvaderMovementState::StepDown)
		{
			VelocityX = -VelocityX;
			Position.y += VelocityY;
			IdleAnimation();
		}
		else if (InvaderController::MovementState == InvaderMovementState::StepSide)
		{
			Position.x += VelocityX;
			IdleAnimation();
		}
		// roll to see if missile is fired
		if (rand() % 10000 < 15)
		{
			pMissile->Shoot(this);
		}
	}
}

void Invader::AssignMissile(Missile* _pMissile)
{
	pMissile = _pMissile;
}

void Invader::IdleAnimation()
{
	if (ArmsUp)
	{
		if (mSpecies == Invader::Species::Squid)
		{
			Sprite = &ResourceManager::GetTexture("squid_down");
		}
		else if (mSpecies == Invader::Species::Crab)
		{
			Sprite = &ResourceManager::GetTexture("crab_down");
		}
		else
		{
			Sprite = &ResourceManager::GetTexture("octopus_down");
		}
	}
	else
	{
		if (mSpecies == Invader::Species::Squid)
		{
			Sprite = &ResourceManager::GetTexture("squid_up");
		}
		else if (mSpecies == Invader::Species::Crab)
		{
			Sprite = &ResourceManager::GetTexture("crab_up");
		}
		else
		{
			Sprite = &ResourceManager::GetTexture("octopus_up");
		}
	}
	ArmsUp = !ArmsUp;
}