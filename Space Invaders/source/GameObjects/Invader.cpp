#include "Invader.h"
#include "InvaderController.h"
#include "ResourceManager.h"


Invader::Invader(Species _species, glm::vec2 _position)
	: GameObject()
	, mSpecies(_species)
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

void Invader::Update(float dt)
{
	GameObject::Update(dt);

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