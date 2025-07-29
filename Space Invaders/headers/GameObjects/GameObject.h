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
    GameObject(Texture2D& _sprite);
    // updates object
    virtual void Update(float dt) = 0;
    // draws sprite
    virtual void Draw(SpriteRenderer& renderer);

protected:
    // render state
    Texture2D& Sprite;
    glm::vec3 Color;
    // object state
    float Velocity;
    float Rotation;
    bool IsSolid;
};