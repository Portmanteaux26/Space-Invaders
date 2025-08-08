#include "Invader.h"


Invader::Invader(Texture2D& _sprite)
	: GameObject(_sprite)
{
	Size = glm::vec2(Sprite.Width, Sprite.Height);
	Position = glm::vec2(GameConstants::PlayableX / 2.0f - Size.x / 2.0f, GameConstants::PlayableY / 2.0f);
	CollisionID = ColMaskInvader;
	CanCollideWith = ColMaskLaser;
}

void Invader::Update(float dt)
{
	if (Collided)
	{
		Destroyed = true;
		Collided = false;
	}
}