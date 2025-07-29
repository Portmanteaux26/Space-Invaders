#pragma once

#include "GameConstants.h"
#include "GameObject.h"


class Invader : public GameObject
{
public:
	Invader(Texture2D& _sprite);
	virtual void Update(float dt) override;
};