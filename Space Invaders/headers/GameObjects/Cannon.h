#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GameConstants.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Laser.h"


class Cannon : public GameObject
{
public:
    // holds a pointer to its laser
    Laser* pLaser;
    
    Cannon(Texture2D& _sprite);
    ~Cannon();
    virtual void Update(float dt) override;
    void AssignLaser(Laser* _pLaser);

private:
    float VelocityX;
    
    void ProcessInput(float dt);
};