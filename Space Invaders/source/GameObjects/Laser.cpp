#include "Laser.h"


Laser::Laser(glm::vec2 pos, glm::vec2 size, const Texture2D& sprite, glm::vec3 color, float velocity)
	: GameObject(pos, size, sprite, color, velocity)
{ }

void Laser::Update(float dt)
{
    if (this->Destroyed == false)
    {
        this->Position.y -= this->Velocity * dt;
    }
    if (this->Position.y <= 0.0f)
    {
        this->Destroyed = true;
    }
}