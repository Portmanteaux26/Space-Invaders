#include "GameObject.h"


GameObject::GameObject()
    : Size(glm::vec2(0.0f))
    , Position(glm::vec2(0.0f))
    , Collided(false)
    , Destroyed(false)
    , CollisionID()
    , CanCollideWith()
    , Sprite(nullptr)
    , Color(glm::vec3(1.0f))
    , Rotation(0.0f)
{ }

void GameObject::Update(float dt)
{
    if (Collided)
    {
        Destroyed = true;
        Collided = false;
    }
}

void GameObject::Draw(SpriteRenderer& renderer)
{
    if (!Destroyed)
    {
        renderer.DrawSprite(*Sprite, Position, Size, Rotation, Color);
    }
}