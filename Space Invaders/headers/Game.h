#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Cannon.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Laser.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"


class Game
{
public:
    enum class GameState
    {
        GAME_ACTIVE,
        GAME_MENU,
        GAME_WIN
    };
    // game state members
    const unsigned int Width;
    const unsigned int Height;
    Game::GameState State;
    SpriteRenderer* Renderer;
    Cannon* Cannon1;
    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();
    // game loop
    void ProcessInput(float dt) const;
    void Update(float dt);
    void Render() const;

private:
    // initializes game state (load all shaders/textures/levels)
    void Init();
};