#pragma once

#include <vector>

#include "GameObject.h"


class ObjectManager
{
public:
	std::vector<GameObject*> GameObjects;

	static ObjectManager& Get();
	void Add(GameObject* NewObject);
	void Clear();
	void Update(float dt) const;
	void Render(SpriteRenderer* Renderer) const;

private:
	// private constructor
	ObjectManager() {}
	bool CheckOverlap(const GameObject* object1, const GameObject* object2) const;
	void CheckCollision(GameObject* object1) const;
};