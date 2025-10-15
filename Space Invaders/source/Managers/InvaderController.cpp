#include "Invader.h"
#include "InvaderController.h"
#include "ObjectManager.h"


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
	// interpolate step speed based on number of invaders left
	const float active = static_cast<float>(ObjectManager::Get().ActiveInvaders);
	const float total = static_cast<float>(InvaderGroup.size());
	const float ratio = 1.0f - active / total;
	const float StepSpeed = GameConstants::MaxStepSpeed + ratio * (GameConstants::MinStepSpeed - GameConstants::MaxStepSpeed);
	// execute correct step if enough time has elapsed
	if (TimeElapsed >= StepSpeed)
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
		if (invader->mState == GameObject::State::Active)
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