#pragma once

#include "GameObject.h"


class ScoreDisplay : public GameObject
{
public:
	enum class DigitPlace
	{
		Ones,
		Tens,
		Hundreds,
	};
	DigitPlace mDigitPlace;
	unsigned int value = 0;

	ScoreDisplay(DigitPlace _place);
	void Update(float dt) override;
};