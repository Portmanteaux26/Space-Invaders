#pragma once

#include <vector>

#include "GameConstants.h"

class Invader;


class InvaderController
{
public:
    void Add(Invader* pInvader);
    void Update(float dt);
    static bool StepDownFlag;
    static bool StepSideFlag;

private:
    std::vector<Invader*> Invaders;
    float TimeElapsed = 0.0f;

    bool ShouldStepDown() const;
};