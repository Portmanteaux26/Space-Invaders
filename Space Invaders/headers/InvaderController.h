#pragma once

#include <vector>

#include "GameConstants.h"
#include "Invader.h"


class InvaderController
{
public:
    void Add(Invader* pInvader);
    void Update(float dt);

private:
    std::vector<Invader*> Invaders;
    float VelocityX = 8.0f;
    float VelocityY = 32.0f;

    bool CheckEdgeCollision() const;
};