#pragma once

#include "GameObject.h"


class Laser : public GameObject
{
public:
    Laser();
    virtual void Update(float dt) override;
    void Shoot(const GameObject* shooter);

private:
    float VelocityY = 750.0f;
};