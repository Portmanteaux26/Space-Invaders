#include "InvaderController.h"


void InvaderController::Add(Invader* pInvader)
{
	Invaders.push_back(pInvader);
}

void InvaderController::Update(float dt)
{
	for (Invader* invader : Invaders)
	{
		if (!invader->Destroyed)
		{
			invader->Position.x += VelocityX * dt;
		}
	}

	if (CheckEdgeCollision())
	{
		VelocityX = -VelocityX;
		for (Invader* invader : Invaders)
		{
			if (!invader->Destroyed)
			{
				invader->Position.y += VelocityY;
			}
		}
	}
}

bool InvaderController::CheckEdgeCollision() const
{
	for (const Invader* invader : Invaders)
	{
		if (!invader->Destroyed)
		{
			if ((VelocityX > 0 && invader->Position.x + invader->Size.x >= GameConstants::PlayableX) ||
				(VelocityX < 0 && invader->Position.x <= 0.0f))
			{
				return true;
			}
		}
	}

	return false;
}