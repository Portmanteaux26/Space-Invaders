#pragma once

#include "GameObject.h"


class Invader : public GameObject
{
public:
	Invader(Texture2D& _sprite, glm::vec2 _position);
	virtual void Update(float dt) override;
	float VelocityX = 8.0f;
	float VelocityY = 32.0f;
};