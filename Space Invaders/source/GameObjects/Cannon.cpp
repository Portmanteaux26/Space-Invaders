#include "Cannon.h"


Cannon::Cannon(const Texture2D& _sprite)
	: GameObject(_sprite)
{
    Size = glm::vec2(100.0f, 20.0f);
    Position = glm::vec2(GameConstants::PlayableX / 2.0f - this->Size.x / 2.0f, GameConstants::PlayableY - this->Size.y);
    Velocity = 500.0f;
    myLaser = new Laser(ResourceManager::GetTexture("laser"));
}

Cannon::~Cannon()
{
    delete myLaser;
}

void Cannon::ProcessInput(float dt)
{
    float right_bound = GameConstants::PlayableX - this->Size.x;
    float distance = this->Velocity * dt;
    // move left
    if (InputManager::Get().keys[GLFW_KEY_A])
    {
        if (this->Position.x <= 0.0f)
        {
            this->Position.x = 0.0f;
        }
        else
        {
            this->Position.x -= distance;
        }
    }
    // move right
    if (InputManager::Get().keys[GLFW_KEY_D])
    {
        if (this->Position.x >= right_bound)
        {
            this->Position.x = right_bound;
        }
        else
        {
            this->Position.x += distance;
        }
    }
    // shoot laser
    if (InputManager::Get().keys[GLFW_KEY_SPACE])
    {
        if (myLaser->Destroyed)
        {
            myLaser->Destroyed = false;
            myLaser->Position.x = this->Position.x + this->Size.x / 2.0f - myLaser->Size.x / 2.0f;
            myLaser->Position.y = this->Position.y - this->Size.y;
        }
    }
}

void Cannon::Update(float dt)
{
    // update laser first
    myLaser->Update(dt);
    // then process input
    this->ProcessInput(dt);
}