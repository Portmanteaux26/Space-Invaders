#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Cannon.h"
#include "GameConstants.h"
#include "InputManager.h"


Cannon::Cannon(Texture2D* _sprite)
	: GameObject(_sprite)
{
    Size = glm::vec2(Sprite->Width, Sprite->Height);
    float x = GameConstants::PlayableX / 2.0f - this->Size.x / 2.0f;
    float y = GameConstants::PlayableY - this->Size.y - 128.0f;
    Position = glm::vec2(x, y);
    CollisionID = ColMaskCannon;
    CanCollideWith = CollisionMask(ColMaskInvader | ColMaskMissile);
    Color = glm::vec3(0.0f, 1.0f, 0.0f);
    pLaser = nullptr;
    VelocityX = 500.0f;
}

Cannon::~Cannon() {}

void Cannon::ProcessInput(float dt)
{
    float right_bound = GameConstants::PlayableX - this->Size.x;
    float distance = this->VelocityX * dt;
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
    if (InputManager::Get().keys[GLFW_KEY_D])
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
    if (InputManager::Get().keys[GLFW_KEY_SPACE])
    {
        pLaser->Shoot(this);
    }
}

void Cannon::Update(float dt)
{
    GameObject::Update(dt);

    if (!Destroyed)
    {
        ProcessInput(dt);
    }
}

void Cannon::AssignLaser(Laser* _pLaser)
{
    pLaser = _pLaser;
}