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
    
    void ProcessInput(float dt);
};