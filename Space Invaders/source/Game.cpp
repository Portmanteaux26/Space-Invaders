#include "Cannon.h"
#include "Game.h"
#include "Invader.h"
#include "ObjectManager.h"
#include "ResourceManager.h"


Game::Game()
    : State(Game::GameState::GAME_ACTIVE)
    , Width(GameConstants::PlayableX)
    , Height(GameConstants::PlayableY)
{
    Game::Init();
}

Game::~Game()
{
   delete Renderer;
   ObjectManager::Get().Clear();
}

void Game::Init()
{
    BuildRenderer();
    LoadTextures();
    ConfigureGameObjects();
}

void Game::BuildRenderer()
{
    ResourceManager::LoadShader("resources/shaders/sprite.vs", "resources/shaders/sprite.fs", nullptr, "sprite");
    glm::mat4 projection = glm::ortho(0.0f, this->Width, this->Height, 0.0f, -1.0f, 1.0f);
    Shader SpriteShader = ResourceManager::GetShader("sprite");
    SpriteShader.Use();
    SpriteShader.SetInteger("image", 0);
    SpriteShader.SetMatrix4("projection", projection);
    Renderer = new SpriteRenderer(SpriteShader);
}

void Game::LoadTextures() const
{
    ResourceManager::LoadTexture("resources/textures/cannon.png", true, "cannon");
    ResourceManager::LoadTexture("resources/textures/laser.png", true, "laser");
    ResourceManager::LoadTexture("resources/textures/squid_down.png", true, "squid_down");
    ResourceManager::LoadTexture("resources/textures/squid_up.png", true, "squid_up");
    ResourceManager::LoadTexture("resources/textures/crab_down.png", true, "crab_down");
    ResourceManager::LoadTexture("resources/textures/crab_up.png", true, "crab_up");
    ResourceManager::LoadTexture("resources/textures/octopus_down.png", true, "octopus_down");
    ResourceManager::LoadTexture("resources/textures/octopus_up.png", true, "octopus_up");
}

void Game::ConfigureGameObjects()
{
    // configure player's Cannon
    Cannon* Player = new Cannon();
    ObjectManager::Get().Add(Player);
    // configure player's Laser
    Laser* PlayerLaser = new Laser();
    Player->AssignLaser(PlayerLaser);
    ObjectManager::Get().Add(PlayerLaser);
    // configure Invaders
    glm::vec2 InvaderPosition = glm::vec2(GameConstants::InvaderInitX, GameConstants::InvaderInitY);
    for (int i = 0; i < GameConstants::NumRows; i++)
    {
        Invader::Species rowSpecies;
        if (i == 0)
        {
            rowSpecies = Invader::Species::Squid;
        }
        else if (i < 3)
        {
            rowSpecies = Invader::Species::Crab;
        }
        else
        {
            rowSpecies = Invader::Species::Octopus;
        }
        for (int j = 0; j < GameConstants::InvadersPerRow; j++)
        {
            Invader* newInvader = new Invader(rowSpecies, InvaderPosition);
            ObjectManager::Get().Add(newInvader);
            iController.Add(newInvader);
            InvaderPosition.x += GameConstants::InvaderStepX;
        }
        // reset X offset and increment Y offset for next row
        InvaderPosition.x = GameConstants::InvaderInitX;
        InvaderPosition.y += GameConstants::InvaderStepY;
    }
}

void Game::ProcessInput(float dt) const
{

    if (this->State == Game::GameState::GAME_ACTIVE)
    {
        // for pausing, etc
    }
}

void Game::Update(float dt)
{
    if (this->State == Game::GameState::GAME_ACTIVE)
    {
        iController.Update(dt);
        ObjectManager::Get().Update(dt);
    }
}

void Game::Render() const
{
    if (this->State == Game::GameState::GAME_ACTIVE)
    {
        ObjectManager::Get().Render(Renderer);
    }
}