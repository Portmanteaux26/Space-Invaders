#include "Game.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"


Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE)
    , Keys()
    , Width(width)
    , Height(height)
{
    
}

Game::~Game()
{
    delete Renderer;
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
    ResourceManager::LoadTexture("resources/textures/paddle.png", true, "paddle");
    // configure game objects
    glm::vec2 playerPos = glm::vec2(this->Width / 2.0f - PLAYER_SIZE.x / 2.0f, this->Height - PLAYER_SIZE.y);
    Player = new GameObject(playerPos, PLAYER_SIZE, ResourceManager::GetTexture("paddle"));
}

void Game::Update(float dt)
{

}

void Game::ProcessInput(float dt) const
{
    float right_bound = this->Width - Player->Size.x;

    if (this->State == GAME_ACTIVE)
    {
        float velocity = PLAYER_VELOCITY * dt;
        // move playerboard
        if (this->Keys[GLFW_KEY_A]) // move left
        {
            if (Player->Position.x <= 0.0f)
            {
                Player->Position.x = 0.0f;
            }
            else
            {
                Player->Position.x -= velocity;
            }
        }
        if (this->Keys[GLFW_KEY_D]) // move right
        {
            if (Player->Position.x >= right_bound)
            {
                Player->Position.x = right_bound;
            }
            else
            {
                Player->Position.x += velocity;
            }
        }
    }
}

void Game::Render() const
{
    if (this->State == GAME_ACTIVE)
    {
        // draw player
        Player->Draw(*Renderer);
    }
}