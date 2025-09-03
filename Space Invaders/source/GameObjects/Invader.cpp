#include "Invader.h"
#include "InvaderController.h"
#include "ResourceManager.h"


Invader::Invader(Texture2D* _sprite, Species _species, glm::vec2 _position)
	: GameObject(_sprite)
	, mSpecies(_species)
{
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
		if (mSpecies == Invader::Species::Crab)
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
		if (mSpecies == Invader::Species::Crab)
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