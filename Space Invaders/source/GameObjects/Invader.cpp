#include "Invader.h"
#include "InvaderController.h"


Invader::Invader(Texture2D& _sprite, glm::vec2 _position)
	: GameObject(_sprite)
{
	Size = glm::vec2(Sprite.Width, Sprite.Height);
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
	}
	if (InvaderController::MovementState == InvaderMovementState::StepSide)
	{
		Position.x += VelocityX;
	}
}