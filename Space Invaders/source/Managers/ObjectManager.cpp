#include "GameObject.h"
#include "ObjectManager.h"


ObjectManager& ObjectManager::Get()
{
	static ObjectManager Manager;
	return Manager;
}

void ObjectManager::Add(GameObject* NewObject)
{
	GameObjects.push_back(NewObject);
}

void ObjectManager::Clear()
{
	for (GameObject* object : GameObjects)
	{
		delete object;
	}
    GameObjects.clear();
}

bool ObjectManager::CheckOverlap(GameObject* object1, GameObject* object2) const
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

void ObjectManager::CheckCollision(GameObject* object1) const
{
    if (object1->mState == GameObject::State::Active || object1->mState == GameObject::State::Collided)
    {
        for (GameObject* object2 : GameObjects)
        {
            if (object2->mState == GameObject::State::Active || object2->mState == GameObject::State::Collided)
            {
                if (CheckOverlap(object1, object2))
                {
                    object1->mState = GameObject::State::Collided;
                }
            }
        }
    }
}

void ObjectManager::Update(float dt) const
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

void ObjectManager::Render(SpriteRenderer* Renderer) const
{
    for (GameObject* object : GameObjects)
    {
        object->Draw(*Renderer);
    }
}