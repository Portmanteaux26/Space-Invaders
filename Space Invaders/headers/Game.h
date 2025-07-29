#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Cannon.h"
#include "GameConstants.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Invader.h"
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
    const float Width;
    const float Height;
    Game::GameState State;
    SpriteRenderer* Renderer;
    Cannon* Cannon1;
    Invader* Invader1;
    
    // constructor/destructor
    Game();
    ~Game();
    // game loop
    void ProcessInput(float dt) const;
    void TestCollision();
    void Update(float dt);
    void Render() const;

private:
    // initializes game state (load all shaders/textures/levels)
    void Init();
};