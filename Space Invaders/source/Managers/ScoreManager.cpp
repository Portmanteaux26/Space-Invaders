#include <iostream>

#include "ScoreDisplay.h"
#include "ScoreManager.h"


ScoreManager& ScoreManager::Get()
{
	static ScoreManager Manager;
	return Manager;
}

void ScoreManager::Add(ScoreDisplay* NewObject)
{
	ScoreObjects.push_back(NewObject);
}

void ScoreManager::UpdateScore(unsigned int points)
{
	CurrentScore += points;
	std::cout << "Score: " << CurrentScore << std::endl;

	ScoreObjects[0]->value = (CurrentScore / 100) % 10; // Hundreds
	ScoreObjects[1]->value = (CurrentScore / 10) % 10;  // Tens
	ScoreObjects[2]->value = CurrentScore % 10;         // Ones
}