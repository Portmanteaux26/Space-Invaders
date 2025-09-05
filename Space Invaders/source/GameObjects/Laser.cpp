#include "Laser.h"
#include "ResourceManager.h"


Laser::Laser()
	: GameObject()
{
    Sprite = &ResourceManager::GetTexture("laser");
    Size = glm::vec2(Sprite->Width, Sprite->Height);
    mState = GameObject::State::Destroyed;
    CollisionID = ColMaskLaser;
    CanCollideWith = CollisionMask(ColMaskInvader | ColMaskBunker);
    VelocityY = 500.0f;
}

void Laser::Update(float dt)
{
    if (mState == GameObject::State::Collided)
    {
        mState = GameObject::State::Destroyed;
    }

    else if (mState == GameObject::State::Active)
    {
        Position.y -= VelocityY * dt;

        if (Position.y <= 0.0f)
        {
            mState = GameObject::State::Collided;
        }
    }
    
}

void Laser::Shoot(const GameObject* shooter)
{
    if (mState == GameObject::State::Destroyed)
    {
        mState = GameObject::State::Active;
        this->Position.x = shooter->Position.x + shooter->Size.x / 2.0f - this->Size.x / 2.0f;
        this->Position.y = shooter->Position.y - this->Size.y;
    }
}