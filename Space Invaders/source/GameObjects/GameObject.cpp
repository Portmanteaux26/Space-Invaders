#include "GameObject.h"


GameObject::GameObject()
    : mState(GameObject::State::Active)
    , CollisionID()
    , CanCollideWith()
    , Size(glm::vec2(0.0f))
    , Position(glm::vec2(0.0f))
    , Sprite(nullptr)
    , Color(glm::vec3(1.0f))    // white
    , Rotation(0.0f)
{ }

void GameObject::DoCollision(const GameObject* partner)
{
    mState = GameObject::State::Destroyed;
}

void GameObject::Draw(SpriteRenderer& renderer)
{
    if (mState == GameObject::State::Active || mState == GameObject::State::Exploding)
    {
        renderer.DrawSprite(*Sprite, Position, Size, Rotation, Color);
    }
}