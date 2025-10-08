#include "ResourceManager.h"
#include "ScoreDisplay.h"


ScoreDisplay::ScoreDisplay(DigitPlace _place)
	: GameObject()
	, mDigitPlace(_place)
{
	Sprite = &ResourceManager::GetTexture("number_0");
	Size = glm::vec2(Sprite->Width, Sprite->Height);
	CollisionID = CollisionMask::ColMaskNone;
	CanCollideWith = CollisionMask::ColMaskNone;

	if (mDigitPlace == DigitPlace::Ones)
	{
		Position.x += 2 * Size.x;
	}
	else if (mDigitPlace == DigitPlace::Tens)
	{
		Position.x += Size.x;
	}
}

void ScoreDisplay::Update(float dt)
{
	if (value == 0)
	{
		Sprite = &ResourceManager::GetTexture("number_0");
	}
	else if (value == 1)
	{
		Sprite = &ResourceManager::GetTexture("number_1");
	}
	else if (value == 2)
	{
		Sprite = &ResourceManager::GetTexture("number_2");
	}
	else if (value == 3)
	{
		Sprite = &ResourceManager::GetTexture("number_3");
	}
	else if (value == 4)
	{
		Sprite = &ResourceManager::GetTexture("number_4");
	}
	else if (value == 5)
	{
		Sprite = &ResourceManager::GetTexture("number_5");
	}
	else if (value == 6)
	{
		Sprite = &ResourceManager::GetTexture("number_6");
	}
	else if (value == 7)
	{
		Sprite = &ResourceManager::GetTexture("number_7");
	}
	else if (value == 8)
	{
		Sprite = &ResourceManager::GetTexture("number_8");
	}
	else if (value == 9)
	{
		Sprite = &ResourceManager::GetTexture("number_9");
	}
}