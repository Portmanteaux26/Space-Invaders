#include "Cannon.h"


Cannon::Cannon(glm::vec2 pos, glm::vec2 size, const Texture2D& sprite, glm::vec3 color, float velocity)
	: GameObject(pos, size, sprite, color, velocity)
{
    myLaser = new Laser(pos, glm::vec2(20.0f, 20.0f), ResourceManager::GetTexture("laser"));
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
        if (myLaser->Destroyed == true)
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