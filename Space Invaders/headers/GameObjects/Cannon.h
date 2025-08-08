#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GameConstants.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Laser.h"
#include "ResourceManager.h"


class Cannon : public GameObject
{
public:
    // holds a pointer to its laser
    Laser* pLaser;
    
    Cannon(Texture2D& _sprite);
    ~Cannon();
    virtual void Update(float dt) override;

private:
    void ProcessInput(float dt);
};