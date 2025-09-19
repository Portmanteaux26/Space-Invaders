#pragma once

#include <vector>

#include "GameObject.h"
#include "Texture.h"


class Missile : public GameObject
{
public:
	Missile();
	virtual void Update(float dt) override;
	void Shoot(const GameObject* shooter);

private:
	float ExplosionTimer = 0.0f;
	std::vector<Texture2D*> AnimSprites;
	float VelocityY = 400.0f;
	float AnimTimer = 0.0f;
	std::size_t AnimIndex = 0;

	void AnimCycle(float dt);
};