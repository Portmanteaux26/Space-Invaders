#include "Cannon.h"


Cannon::Cannon(glm::vec2 pos, glm::vec2 size, const Texture2D& sprite, glm::vec3 color, glm::vec2 velocity)
	: GameObject(pos, size, sprite, color, velocity)
{ }