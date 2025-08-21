#include "Laser.h"


Laser::Laser(Texture2D& _sprite)
	: GameObject(_sprite)
{
    Size = glm::vec2(Sprite.Width, Sprite.Height);
    CollisionID = ColMaskLaser;
    CanCollideWith = CollisionMask(ColMaskInvader | ColMaskBunker);
    VelocityY = 500.0f;
}

void Laser::Update(float dt)
{
    GameObject::Update(dt);

    if (!Destroyed)
    {
        Position.y -= VelocityY * dt;
    }
    if (Position.y <= 0.0f)
    {
        Destroyed = true;
    }
}

void Laser::Shoot(const GameObject* shooter)
{
    if (Destroyed)
    {
        Destroyed = false;
        this->Position.x = shooter->Position.x + shooter->Size.x / 2.0f - this->Size.x / 2.0f;
        this->Position.y = shooter->Position.y - this->Size.y;
    }
}