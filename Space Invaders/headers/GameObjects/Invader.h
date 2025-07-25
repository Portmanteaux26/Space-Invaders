#pragma once

#include "GameConstants.h"
#include "GameObject.h"


class Invader : public GameObject
{
public:
	Invader(const Texture2D& sprite);
	virtual void Update(float dt) override;
};