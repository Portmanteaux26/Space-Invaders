#pragma once

#include <glm/glm.hpp>

#include "Texture.h"
#include "SpriteRenderer.h"


class GameObject
{
public:
    // object state
    glm::vec2 Position;
    glm::vec2 Size;
    bool Destroyed;
    
    // constructor
    GameObject(
        glm::vec2 pos,
        glm::vec2 size,
        const Texture2D& sprite,
        glm::vec3 color = glm::vec3(1.0f),
        const float velocity = 500.0f);
    // updates object
    virtual void Update(float dt) = 0;
    // draws sprite
    virtual void Draw(SpriteRenderer& renderer);

protected:
    // render state
    const Texture2D& Sprite;
    glm::vec3 Color;
    // object state
    float Velocity;
    float Rotation = 0.0f;
    bool IsSolid = false;
};