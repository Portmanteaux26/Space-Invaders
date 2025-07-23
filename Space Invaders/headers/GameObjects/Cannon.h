#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GameObject.h"
#include "InputManager.h"


class Cannon : public GameObject
{
public:
	Cannon(
        glm::vec2 pos,
        glm::vec2 size,
        const Texture2D& sprite,
        glm::vec3 color = glm::vec3(1.0f),
        float velocity = 500.0f);
    virtual void Update(float dt) override;
};