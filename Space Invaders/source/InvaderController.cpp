#include "Invader.h"
#include "InvaderController.h"


bool InvaderController::StepDownFlag = false;
bool InvaderController::StepSideFlag = false;


void InvaderController::Add(Invader* pInvader)
{
	Invaders.push_back(pInvader);
}

void InvaderController::Update(float dt)
{
	TimeElapsed += dt;
	StepDownFlag = false;
	StepSideFlag = false;
	if (TimeElapsed >= GameConstants::MaxStepSpeed)
	{
		if (ShouldStepDown())
		{
			StepDownFlag = true;
		}
		else
		{
			StepSideFlag = true;
		}
		TimeElapsed = 0.0f;
	}
}

bool InvaderController::ShouldStepDown() const
{
	for (const Invader* invader : Invaders)
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