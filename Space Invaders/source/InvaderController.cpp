#include "Invader.h"
#include "InvaderController.h"


// initialize static
InvaderMovementState InvaderController::MovementState = InvaderMovementState::None;

void InvaderController::Add(Invader* pInvader)
{
	InvaderGroup.push_back(pInvader);
}

void InvaderController::Update(float dt)
{
	TimeElapsed += dt;
	MovementState = InvaderMovementState::None;
	if (TimeElapsed >= GameConstants::MaxStepSpeed)
	{
		if (ShouldStepDown())
		{
			MovementState = InvaderMovementState::StepDown;
		}
		else
		{
			MovementState = InvaderMovementState::StepSide;
		}
		TimeElapsed = 0.0f;
	}
}

bool InvaderController::ShouldStepDown() const
{
	for (const Invader* invader : InvaderGroup)
	{
		if (!invader->Destroyed)
		{
			if ((invader->Position.x + invader->Size.x + invader->VelocityX >= GameConstants::PlayableX) ||
				(invader->Position.x + invader->VelocityX <= 0.0f))
			{
				return true;
			}
		}
	}

	return false;
}