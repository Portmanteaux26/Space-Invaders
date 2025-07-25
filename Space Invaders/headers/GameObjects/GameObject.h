#pragma once

#include <glm/glm.hpp>

#include "Texture.h"
#include "SpriteRenderer.h"


class GameObject
{
public:
    // object state
    glm::vec2 Size;
    glm::vec2 Position;
    bool Destroyed;
    
    // constructor
    GameObject(const Texture2D& sprite);
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
    float Rotation;
    bool IsSolid;
};