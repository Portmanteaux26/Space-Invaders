#pragma once


class InputManager
{
public:
	bool keys[1024];
	static InputManager& Get();

private:
	// private constructor
	InputManager() { }
};