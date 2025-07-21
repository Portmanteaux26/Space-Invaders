#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H


class InputManager
{
public:
	bool keys[1024];
	static InputManager& Get();

private:
	// constructor
	InputManager() { }
};


#endif