#pragma once

#include <glm/glm.hpp>

#include "Texture.h"
#include "SpriteRenderer.h"


class GameObject
{
public:
    enum class State
    {
        Active,
        Exploding,
        Destroyed
    };
    State mState;

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
    
    glm::vec2 Size;
    glm::vec2 Position;
    
    virtual void DoCollision(const GameObject* partner);
    virtual void Update(float dt) = 0;
    virtual void Draw(SpriteRenderer& renderer);

protected:
    // render state
    Texture2D* Sprite;
    glm::vec3 Color;
    // object state
    float Rotation;

    // protected constructor
    GameObject();
};