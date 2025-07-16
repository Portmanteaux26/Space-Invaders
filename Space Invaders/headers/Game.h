#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


// Represents the current state of the game
const enum GameState
{
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};
// Initial size of the player paddle
const glm::vec2 PLAYER_SIZE(100.0f, 20.0f);
// Initial velocity of the player paddle
const float PLAYER_VELOCITY(500.0f);


class Game
{
public:
    // game state
    GameState               State;
    bool                    Keys[1024];
    const unsigned int      Width, Height;
    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();
    // initializes game state (load all shaders/textures/levels)
    void Init();
    // game loop
    void ProcessInput(float dt) const;
    void Update(float dt);
    void Render() const;

private:

};

#endif