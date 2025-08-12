#pragma once

#include "GameObject.h"


class Laser : public GameObject
{
public:
    Laser(Texture2D& _sprite);
    virtual void Update(float dt) override;
    void Shoot(const GameObject* shooter);
};