#include "Game.h"


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
    // load shaders
    ResourceManager::LoadShader("resources/shaders/sprite.vs", "resources/shaders/sprite.fs", nullptr, "sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, this->Width, this->Height, 0.0f, -1.0f, 1.0f);
    Shader SpriteShader = ResourceManager::GetShader("sprite");
    SpriteShader.Use();
    SpriteShader.SetInteger("image", 0);
    SpriteShader.SetMatrix4("projection", projection);
    // create sprite renderer
    Renderer = new SpriteRenderer(SpriteShader);
    // load textures
    ResourceManager::LoadTexture("resources/textures/cannon.png", true, "cannon");
    ResourceManager::LoadTexture("resources/textures/laser.png", true, "laser");
    ResourceManager::LoadTexture("resources/textures/crab_down.png", true, "crab_down");
    ResourceManager::LoadTexture("resources/textures/crab_up.png", true, "crab_up");
    // configure player's Cannon
    Cannon* Player = new Cannon(ResourceManager::GetTexture("cannon"));
    ObjectManager::Get().Add(Player);
    // configure player's Laser
    Laser* PLayerLaser = new Laser(ResourceManager::GetTexture("laser"));
    Player->AssignLaser(PLayerLaser);
    ObjectManager::Get().Add(PLayerLaser);
    // configure invaders
    int numRows = 5;
    int InvadersPerRow = 11;
    float InvaderInitX = 94.0f;
    float InvaderInitY = 128.0f;
    float InvaderGap = 24.0f;
    glm::vec2 InvaderPosition = glm::vec2(InvaderInitX, InvaderInitY);
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < InvadersPerRow; j++)
        {
            Invader* newInvader = new Invader(ResourceManager::GetTexture("crab_down"), InvaderPosition);
            ObjectManager::Get().Add(newInvader);
            InvaderPosition.x += newInvader->Size.x + InvaderGap;
            if (j == InvadersPerRow - 1)
            {
                InvaderPosition.x = InvaderInitX;
                InvaderPosition.y += newInvader->Size.y + InvaderGap;
            }
        }
    }
}

void Game::ProcessInput(float dt) const
{

    if (this->State == Game::GameState::GAME_ACTIVE)
    {
        // for pausing, etc
    }
}

void Game::Update(float dt) const
{
    if (this->State == Game::GameState::GAME_ACTIVE)
    {
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