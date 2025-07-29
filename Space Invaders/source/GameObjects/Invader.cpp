#include "Invader.h"


Invader::Invader(Texture2D& _sprite)
	: GameObject(_sprite)
{
	Size = glm::vec2(Sprite.Width, Sprite.Height);
	Position = glm::vec2(GameConstants::PlayableX / 2.0f - Size.x / 2.0f, GameConstants::PlayableY / 2.0f);
}

void Invader::Update(float dt)
{
	if (! Destroyed)
	{
		Rotation += 0.1f;
		if (Rotation >= 360.0f)
		{
			Rotation = 0.0f;
		}
	}
}