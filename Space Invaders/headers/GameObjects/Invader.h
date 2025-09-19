#pragma once

#include "GameObject.h"
#include "Missile.h"


class Invader : public GameObject
{
public:
	enum class Species
	{
		Squid,
		Crab,
		Octopus
	};
	float VelocityX = 8.0f;
	float VelocityY = 32.0f;
	Species mSpecies;
	// holds a pointer to a missile
	Missile* pMissile;

	Invader(Species _species, glm::vec2 _position);
	void DoCollision(const GameObject* partner) override;
	void Update(float dt) override;
	void AssignMissile(Missile* _pMissile);

private:
	float ExplosionTimer = 0.0f;
	bool ArmsUp = false;

	void IdleAnimation();
};