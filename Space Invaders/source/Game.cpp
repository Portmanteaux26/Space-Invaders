#include "Cannon.h"
#include "Game.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Laser.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"


Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE)
    , Width(width)
    , Height(height)
{
    Game::Init();
}

Game::~Game()
{
    delete Renderer;
    delete Cannon1;
    delete Laser1;
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
    glm::vec2 playerPos = glm::vec2(this->Width / 2.0f - PLAYER_SIZE.x / 2.0f, this->Height - PLAYER_SIZE.y);
    glm::vec2 storage = glm::vec2(this->Width / 2.0f, this->Height / 2.0f);
    Cannon1 = new Cannon(playerPos, PLAYER_SIZE, ResourceManager::GetTexture("cannon"));
    Laser1 = new Laser(storage, LASER_SIZE, ResourceManager::GetTexture("laser"));
}

void Game::Update(float dt)
{
    if (Laser1->Destroyed == false)
    {
        Laser1->Position.y -= LASER_VELOCITY * dt;
    }
    if (Laser1->Position.y <= 0.0f)
    {
        Laser1->Destroyed = true;
    }
    
}

void Game::ProcessInput(float dt, InputManager& input_manager) const
{

    if (this->State == GAME_ACTIVE)
    {
        float right_bound = this->Width - Cannon1->Size.x;
        float velocity = PLAYER_VELOCITY * dt;
        // move playerboard
        if (input_manager.keys[GLFW_KEY_A]) // move left
        {
            if (Cannon1->Position.x <= 0.0f)
            {
                Cannon1->Position.x = 0.0f;
            }
            else
            {
                Cannon1->Position.x -= velocity;
            }
        }
        if (input_manager.keys[GLFW_KEY_D]) // move right
        {
            if (Cannon1->Position.x >= right_bound)
            {
                Cannon1->Position.x = right_bound;
            }
            else
            {
                Cannon1->Position.x += velocity;
            }
        }
        if (input_manager.keys[GLFW_KEY_SPACE]) // shoot laser
        {
            if (Laser1->Destroyed == true)
            {
                Laser1->Destroyed = false;
                Laser1->Position.x = Cannon1->Position.x + PLAYER_SIZE.x / 2.0f - LASER_SIZE.x / 2.0f;
                Laser1->Position.y = Cannon1->Position.y - PLAYER_SIZE.y;
            }
        }
    }
}

void Game::Render() const
{
    if (this->State == GAME_ACTIVE)
    {
        // draw player
        Cannon1->Draw(*Renderer);
        // draw laser
        if (Laser1->Destroyed == false)
        {
            Laser1->Draw(*Renderer);
        }
    }
}