#pragma once

#include <vector>

#include "GameConstants.h"
#include "Invader.h"


class InvaderController
{
public:
    InvaderController();
    void Add(Invader* invader);
    void Update(float dt);

private:
    std::vector<Invader*> Invaders;
    float VelocityX;
    float VelocityY;

    bool CheckEdgeCollision() const;
};