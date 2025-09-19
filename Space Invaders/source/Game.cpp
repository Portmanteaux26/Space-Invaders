#include "Cannon.h"
#include "Game.h"
#include "Invader.h"
#include "ObjectManager.h"
#include "Missile.h"
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
    ResourceManager::LoadTexture("resources/textures/invader_explosion.png", true, "invader_explosion");
    ResourceManager::LoadTexture("resources/textures/plunger_0.png", true, "plunger_0");
    ResourceManager::LoadTexture("resources/textures/plunger_1.png", true, "plunger_1");
    ResourceManager::LoadTexture("resources/textures/plunger_2.png", true, "plunger_2");
    ResourceManager::LoadTexture("resources/textures/plunger_3.png", true, "plunger_3");
    ResourceManager::LoadTexture("resources/textures/missile_explosion.png", true, "missile_explosion");
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
    ConfigureInvaders();
    // configure missiles
    Missile* Plunger = new Missile();
    ObjectManager::Get().Add(Plunger);
    for (Invader* invader : iController.InvaderGroup)
    {
        invader->AssignMissile(Plunger);
    }
}

void Game::ConfigureInvaders()
{
    glm::vec2 rowStartPos = glm::vec2(GameConstants::InvaderInitX, GameConstants::InvaderInitY);
    for (int row = 0; row < GameConstants::NumRows; row++)
    {
        Texture2D* rowSprite = nullptr;
        Invader::Species rowSpecies;
        // cache sprites and species enums for inner loop
        if (row == 0)
        {
            rowSprite = &ResourceManager::GetTexture("squid_down");
            rowSpecies = Invader::Species::Squid;
        }
        else if (row < 3)
        {
            rowSprite = &ResourceManager::GetTexture("crab_down");
            rowSpecies = Invader::Species::Crab;
        }
        else
        {
            rowSprite = &ResourceManager::GetTexture("octopus_down");
            rowSpecies = Invader::Species::Octopus;
        }
        for (int col = 0; col < GameConstants::InvadersPerRow; col++)
        {
            // calculate centered position for sprite
            float cellX = rowStartPos.x + col * GameConstants::InvaderCellX;
            float centeredX = cellX + (GameConstants::InvaderCellX - rowSprite->Width) / 2.0f;
            glm::vec2 invaderPos(centeredX, rowStartPos.y);
            // add Invader with appropriate species and position
            Invader* newInvader = new Invader(rowSpecies, invaderPos);
            ObjectManager::Get().Add(newInvader);
            iController.Add(newInvader);
        }
        // increment Y offset for next row
        rowStartPos.y += GameConstants::InvaderCellY;
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