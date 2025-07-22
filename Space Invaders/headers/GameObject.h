#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Texture.h"
#include "SpriteRenderer.h"


class GameObject
{
public:
    // object state
    glm::vec2 Position = glm::vec2(0.0f, 0.0f);
    glm::vec2 Size = glm::vec2(0.0f, 0.0f);
    
    // constructor
    GameObject(
        glm::vec2 pos,
        glm::vec2 size,
        const Texture2D& sprite,
        glm::vec3 color = glm::vec3(1.0f),
        glm::vec2 velocity = glm::vec2(0.0f, 0.0f)
    );
    // draws sprite
    virtual void Draw(SpriteRenderer& renderer);

private:
    // object state
    glm::vec2 Velocity;
    glm::vec3 Color;
    float Rotation = 0.0f;
    bool  IsSolid = false;
    bool  Destroyed = false;
    // render state
    const Texture2D& Sprite;
};