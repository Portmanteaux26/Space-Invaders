#include "Laser.h"


Laser::Laser(const Texture2D& sprite)
	: GameObject(sprite)
{
    Size = glm::vec2(20.0f, 20.0f);
    Velocity = 500.0f;
}

void Laser::Update(float dt)
{
    if (! this->Destroyed)
    {
        this->Position.y -= this->Velocity * dt;
    }
    if (this->Position.y <= 0.0f)
    {
        this->Destroyed = true;
    }
}