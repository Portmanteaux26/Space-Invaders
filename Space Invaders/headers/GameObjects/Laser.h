#pragma once

#include "GameObject.h"


class Laser : public GameObject
{
public:
    Laser(const Texture2D& sprite);
    virtual void Update(float dt) override;
};