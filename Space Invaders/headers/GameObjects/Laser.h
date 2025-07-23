#pragma once

#include "GameObject.h"


class Laser : public GameObject
{
public:
    Laser(
        glm::vec2 pos,
        glm::vec2 size,
        const Texture2D& sprite,
        glm::vec3 color = glm::vec3(1.0f),
        float velocity = 500.0f);
    virtual void Update(float dt) override;
};