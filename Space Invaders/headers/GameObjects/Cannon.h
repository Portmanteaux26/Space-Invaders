#pragma once

#include "GameObject.h"
#include "Laser.h"


class Cannon : public GameObject
{
public:
    // holds a pointer to its laser
    Laser* pLaser;
    
    Cannon();
    void DoCollision(const GameObject* partner);
    void Update(float dt) override;
    void AssignLaser(Laser* _pLaser);

private:
    float VelocityX = 500.0f;
    float ExplosionOffset = 8.0f;
    float ExplosionTimer = 0.0f;
	float AnimTimer = 0.0f;
    
    void ProcessInput(float dt);
	void ExplosionAnimCycle(float dt);
};