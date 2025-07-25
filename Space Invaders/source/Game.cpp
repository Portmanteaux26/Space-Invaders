#include "Game.h"


Game::Game(unsigned int width, unsigned int height)
    : State(Game::GameState::GAME_ACTIVE)
    , Width(width)
    , Height(height)
{
    Game::Init();
}

Game::~Game()
{
    delete Renderer;
    delete Cannon1;
}

void Game::Init()
{
    // load shaders
    ResourceManager::LoadShader("resources/shaders/sprite.vs", "resources/shaders/sprite.fs", nullptr, "sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
    // load textures
    ResourceManager::LoadTexture("resources/textures/paddle.png", true, "cannon");
    ResourceManager::LoadTexture("resources/textures/awesomeface.png", true, "laser");
    // configure game objects
    Cannon1 = new Cannon(ResourceManager::GetTexture("cannon"));
}

void Game::Update(float dt)
{
    if (this->State == Game::GameState::GAME_ACTIVE)
    {
        Cannon1->Update(dt);
    }
}

void Game::ProcessInput(float dt) const
{

    if (this->State == Game::GameState::GAME_ACTIVE)
    {
        // for pausing, etc
    }
}

void Game::Render() const
{
    if (this->State == Game::GameState::GAME_ACTIVE)
    {
        // draw player
        Cannon1->Draw(*Renderer);
        // draw laser
        if (! Cannon1->myLaser->Destroyed)
        {
            Cannon1->myLaser->Draw(*Renderer);
        }
    }
}