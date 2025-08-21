#pragma once

#include "InvaderController.h"
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
    InvaderController iController;
    
    // constructor/destructor
    Game();
    ~Game();
    // game loop
    void ProcessInput(float dt) const;
    void Update(float dt);
    void Render() const;

private:
    void Init();
    void BuildRenderer();
    void LoadTextures() const;
    void ConfigureGameObjects();
};