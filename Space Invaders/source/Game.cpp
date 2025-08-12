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
    for (GameObject* Object : GameObjects)
    {
        delete Object;
    }
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
    // set render-specific controls
    Renderer = new SpriteRenderer(SpriteShader);
    // load textures
    ResourceManager::LoadTexture("resources/textures/cannon.png", true, "cannon");
    ResourceManager::LoadTexture("resources/textures/laser.png", true, "laser");
    ResourceManager::LoadTexture("resources/textures/crab_down.png", true, "crab_down");
    ResourceManager::LoadTexture("resources/textures/crab_up.png", true, "crab_up");
    // configure game objects
    Player = new Cannon(ResourceManager::GetTexture("cannon"));
    PLayerLaser = new Laser(ResourceManager::GetTexture("laser"));
    Player->pLaser = PLayerLaser;
    GameObjects.push_back(Player);
    GameObjects.push_back(PLayerLaser);
    GameObjects.push_back(new Invader(ResourceManager::GetTexture("crab_down")));
}

void Game::ProcessInput(float dt) const
{

    if (this->State == Game::GameState::GAME_ACTIVE)
    {
        // for pausing, etc
    }
}

bool Game::CheckOverlap(GameObject* object1, GameObject* object2) const
{
    if ((object1->CanCollideWith & object2->CollisionID) != 0)
    {
        if (object1->Position.y < object2->Position.y + object2->Size.y &&
            object1->Position.y + object1->Size.y > object2->Position.y)
        {
            if (object1->Position.x < object2->Position.x + object2->Size.x &&
                object1->Position.x + object1->Size.x > object2->Position.x)
            {
                return true;
            }
        }
    }

    return false;
}

void Game::CheckCollision(GameObject* object1) const
{
    if (object1->Destroyed == false)
    {
        for (GameObject* object2 : GameObjects)
        {
            if (object2->Destroyed == false)
            {
                if (CheckOverlap(object1, object2))
                {
                    object1->Collided = true;
                }
            }
        }
    }
}

void Game::Update(float dt) const
{
    if (this->State == Game::GameState::GAME_ACTIVE)
    {
        for (GameObject* object : GameObjects)
        {
            object->Update(dt);
        }
        for (GameObject* object : GameObjects)
        {
            CheckCollision(object);
        }
    }
}

void Game::Render() const
{
    if (this->State == Game::GameState::GAME_ACTIVE)
    {
        for (GameObject* object : GameObjects)
        {
            if (!object->Destroyed)
            {
                object->Draw(*Renderer);
            }
        }
    }
}