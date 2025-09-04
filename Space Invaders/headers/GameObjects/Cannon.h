#pragma once

#include "GameObject.h"
#include "Laser.h"


class Cannon : public GameObject
{
public:
    // holds a pointer to its laser
    Laser* pLaser;
    
    Cannon();
    ~Cannon();
    virtual void Update(float dt) override;
    void AssignLaser(Laser* _pLaser);

private:
    float VelocityX;
    
    void ProcessInput(float dt);
};