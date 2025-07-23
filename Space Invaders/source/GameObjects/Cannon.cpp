#include "Cannon.h"


Cannon::Cannon(glm::vec2 pos, glm::vec2 size, const Texture2D& sprite, glm::vec3 color, float velocity)
	: GameObject(pos, size, sprite, color, velocity)
{ }

void Cannon::Update(float dt)
{
    float right_bound = 600.0f - this->Size.x;
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
}