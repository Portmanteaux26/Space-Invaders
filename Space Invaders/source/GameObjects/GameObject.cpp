#include "GameObject.h"


GameObject::GameObject()
    : Size(glm::vec2(0.0f))
    , Position(glm::vec2(0.0f))
    , mState(GameObject::State::Active)
    , CollisionID()
    , CanCollideWith()
    , Sprite(nullptr)
    , Color(glm::vec3(1.0f))
    , Rotation(0.0f)
{ }


void GameObject::Draw(SpriteRenderer& renderer)
{
    if (mState == GameObject::State::Active || mState == GameObject::State::Exploding)
    {
        renderer.DrawSprite(*Sprite, Position, Size, Rotation, Color);
    }
}