#include "InputManager.h"


InputManager& InputManager::Get()
{
	static InputManager Manager;
	return Manager;
}