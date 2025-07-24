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
    Laser* myLaser;
	Cannon(
        glm::vec2 pos,
        glm::vec2 size,
        const Texture2D& sprite,
        glm::vec3 color = glm::vec3(1.0f),
        float velocity = 500.0f);
    ~Cannon();
    virtual void Update(float dt) override;
private:
    void ProcessInput(float dt);
};