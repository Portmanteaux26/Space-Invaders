#pragma once

#include <glm/glm.hpp>

#include "Texture.h"
#include "SpriteRenderer.h"


class GameObject
{
public:
    enum CollisionMask
    {
        ColMaskNone = 0,
        ColMaskCannon = 1 << 0,
        ColMaskLaser = 1 << 1,
        ColMaskInvader = 1 << 2,
        ColMaskMissile = 1 << 3,
        ColMaskBunker = 1 << 4
    };
    CollisionMask CollisionID;
    CollisionMask CanCollideWith;
    // object state
    glm::vec2 Size;
    glm::vec2 Position;
    bool Collided;
    bool Destroyed;
    
    virtual void Update(float dt);
    virtual void Draw(SpriteRenderer& renderer);

protected:
    // render state
    Texture2D* Sprite;
    glm::vec3 Color;
    // object state
    float Rotation;

    // protected constructor
    GameObject(Texture2D* _sprite);
};