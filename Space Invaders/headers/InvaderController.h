#pragma once

#include <vector>

#include "GameConstants.h"

class Invader;  // avoid circular includes by forward declaring Invader*



enum class InvaderMovementState
{
    None,
    StepSide,
    StepDown
};

class InvaderController
{
public:
    std::vector<Invader*> InvaderGroup;
    static InvaderMovementState MovementState;

    void Add(Invader* pInvader);
    void Update(float dt);

private:
    float TimeElapsed = 0.0f;

    bool ShouldStepDown() const;
};