#pragma once


struct GameConstants
{
	static constexpr float PlayableX = 896.0f;
	static constexpr float PlayableY = 1024.0f;
	static const int NumRows = 5;
	static const int InvadersPerRow = 11;
	static constexpr float InvaderCellX = 16.0f * 4.0f;
	static constexpr float InvaderCellY = 16.0f * 4.0f;
	static constexpr float InvaderInitX = (PlayableX / 2.0f) - ((InvadersPerRow - 1) * InvaderCellX / 2.0f);
	static constexpr float InvaderInitY = 256.0f;
	static constexpr float MaxStepSpeed = 0.8f;
	static constexpr float MinStepSpeed = 0.5f;
};