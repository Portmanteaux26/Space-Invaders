#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <vector>

#include "Cannon.h"
#include "GameConstants.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Invader.h"
#include "Laser.h"
#include "ObjectManager.h"
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
    
    // constructor/destructor
    Game();
    ~Game();
    // game loop
    void ProcessInput(float dt) const;
    void Update(float dt) const;
    void Render() const;

private:
    // initializes game state (load all shaders/textures/GameObjects)
    void Init();
};