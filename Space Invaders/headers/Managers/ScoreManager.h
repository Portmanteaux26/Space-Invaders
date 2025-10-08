#pragma once

#include <vector>

#include "ScoreDisplay.h"


class ScoreManager
{
public:
	unsigned int CurrentScore = 0;
	std::vector<ScoreDisplay*> ScoreObjects;

	static ScoreManager& Get();
	void Add(ScoreDisplay* NewObject);
	void UpdateScore(unsigned int points);

private:
	// private constructor
	ScoreManager() {}
};