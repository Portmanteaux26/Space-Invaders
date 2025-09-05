#pragma once


struct GameConstants
{
	// values are based on arcade version, scaled 4x
	static constexpr float PlayableX = 224.0f * 4.0f;
	static constexpr float PlayableY = 256.0f * 4.0f;
	static const int NumRows = 5;
	static const int InvadersPerRow = 11;
	static constexpr float InvaderCellX = 16.0f * 4.0f;
	static constexpr float InvaderCellY = 16.0f * 4.0f;
	static constexpr float InvaderInitX = (PlayableX - (InvadersPerRow * InvaderCellX)) / 2.0f;
	static constexpr float InvaderInitY = 64.0f * 4.0f;
	// time between steps in seconds
	static constexpr float MaxStepSpeed = 0.7f;
	static constexpr float MinStepSpeed = 0.4f;
};