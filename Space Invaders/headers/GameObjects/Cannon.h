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
    // owns its laser
    Laser* myLaser;
    
    Cannon(Texture2D& _sprite);
    ~Cannon();
    virtual void Update(float dt) override;

private:
    void ProcessInput(float dt);
};