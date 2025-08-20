#pragma once

#include "GameConstants.h"
#include "GameObject.h"
#include "ResourceManager.h"


class Invader : public GameObject
{
public:
	Invader(Texture2D& _sprite, glm::vec2 _position);
};