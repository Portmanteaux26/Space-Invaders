#include "Laser.h"


Laser::Laser(Texture2D& _sprite)
	: GameObject(_sprite)
{
    Size = glm::vec2(20.0f, 20.0f);
    CollisionID = ColMaskLaser;
    CanCollideWith = ColMaskInvader;
    Velocity = 500.0f;
}

void Laser::Update(float dt)
{
    if (Collided)
    {
        Destroyed = true;
        Collided = false;
    }
    if (!Destroyed)
    {
        Position.y -= Velocity * dt;
    }
    if (Position.y <= 0.0f)
    {
        Destroyed = true;
    }
}