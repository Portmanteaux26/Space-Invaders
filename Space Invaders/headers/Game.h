#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "GameObject.h"
#include "InputManager.h"
#include "SpriteRenderer.h"


// Represents the current state of the game
const enum GameState
{
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};
// GameObject globals
const glm::vec2 PLAYER_SIZE(100.0f, 20.0f);
const float PLAYER_VELOCITY(500.0f);
const glm::vec2 LASER_SIZE(20.0f, 20.0f);
const float LASER_VELOCITY(500.0f);


class Game
{
public:
    // game state
    GameState State;
    const unsigned int Width;
    const unsigned int Height;
    SpriteRenderer* Renderer;
    GameObject* Cannon1;
    GameObject* Laser1;
    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();
    // game loop
    void ProcessInput(float dt, InputManager& input_manager) const;
    void Update(float dt);
    void Render() const;

private:
    // initializes game state (load all shaders/textures/levels)
    void Init();
};