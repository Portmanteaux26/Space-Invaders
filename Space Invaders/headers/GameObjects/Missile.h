#pragma once

#include <vector>

#include "GameObject.h"
#include "Texture.h"


class Missile : public GameObject
{
public:
	Missile();
	void DoCollision(const GameObject* partner) override;
	void Update(float dt) override;
	void Shoot(const GameObject* shooter);

private:
	float VelocityY = 300.0f;
	float ExplosionTimer = 0.0f;
	float ExplosionOffset = 8.0f;
	std::vector<Texture2D*> AnimSprites;
	float AnimTimer = 0.0f;
	std::size_t AnimIndex = 0;

	void AnimCycle(float dt);
};