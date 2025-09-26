#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Cannon.h"
#include "GameConstants.h"
#include "InputManager.h"
#include "ResourceManager.h"


Cannon::Cannon()
	: GameObject()
    , pLaser(nullptr)
{
    Sprite = &ResourceManager::GetTexture("cannon");
    Size = glm::vec2(Sprite->Width, Sprite->Height);
    const float x = GameConstants::PlayableX / 2.0f - this->Size.x / 2.0f;
    const float y = GameConstants::PlayableY - this->Size.y - 128.0f;
    Position = glm::vec2(x, y);
    CollisionID = ColMaskCannon;
    CanCollideWith = CollisionMask(ColMaskInvader | ColMaskMissile);
    Color = glm::vec3(0.0f, 1.0f, 0.0f);
}

void Cannon::DoCollision(const GameObject* partner)
{
    if (partner->CollisionID & ColMaskMissile)
    {
        mState = GameObject::State::Exploding;
        Sprite = &ResourceManager::GetTexture("cannon_explosion_0");
        // adjust size and x pos to center explosion
        Size = glm::vec2(Sprite->Width, Sprite->Height);
        Position.x -= ExplosionOffset;
    }
}

void Cannon::Update(float dt)
{
    if (mState == GameObject::State::Exploding)
    {
        if (ExplosionTimer > 1.0f)
        {
            mState = GameObject::State::Active;
            Sprite = &ResourceManager::GetTexture("cannon");
            Size = glm::vec2(Sprite->Width, Sprite->Height);
            const float x = GameConstants::PlayableX / 2.0f - this->Size.x / 2.0f;
            const float y = GameConstants::PlayableY - this->Size.y - 128.0f;
            Position = glm::vec2(x, y);
            ExplosionTimer = 0.0f;
        }
        else
        {
			ExplosionAnimCycle(dt);
			ExplosionTimer += dt;
        }
    }
    else if (mState == GameObject::State::Active)
    {
        ProcessInput(dt);
    }
}

void Cannon::AssignLaser(Laser* _pLaser)
{
    pLaser = _pLaser;
}

void Cannon::ProcessInput(float dt)
{
    float const right_bound = GameConstants::PlayableX - this->Size.x;
    float const distance = this->VelocityX * dt;
    // move left
    if (InputManager::Get().keys[GLFW_KEY_A])
    {
        if (Position.x <= 0.0f)
        {
            Position.x = 0.0f;
        }
        else
        {
            Position.x -= distance;
        }
    }
    // move right
    else if (InputManager::Get().keys[GLFW_KEY_D])
    {
        if (Position.x >= right_bound)
        {
            Position.x = right_bound;
        }
        else
        {
            Position.x += distance;
        }
    }
    // shoot laser
    else if (InputManager::Get().keys[GLFW_KEY_SPACE])
    {
        pLaser->Shoot(this);
    }
}

void Cannon::ExplosionAnimCycle(float dt)
{
    if (AnimTimer > 0.1f)
    {
        if (Sprite == &ResourceManager::GetTexture("cannon_explosion_0"))
        {
			Sprite = &ResourceManager::GetTexture("cannon_explosion_1");
        }
        else
        {
			Sprite = &ResourceManager::GetTexture("cannon_explosion_0");
        }
		AnimTimer = 0.0f;
    }
    else
    {
		AnimTimer += dt;
    }
}