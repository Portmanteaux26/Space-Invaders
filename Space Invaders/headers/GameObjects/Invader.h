#pragma once

#include "GameObject.h"




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

	Invader(Species _species, glm::vec2 _position);
	virtual void Update(float dt) override;

private:
	bool ArmsUp = false;

	void IdleAnimation();
};