#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H


#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Texture.h"
#include "Shader.h"


class SpriteRenderer
{
public:
	// constructor and destructor
	SpriteRenderer(Shader& shader);
	~SpriteRenderer();
	// renders quad texture with a sprite
	void DrawSprite(Texture2D& texture, glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
private:
	// state
	Shader shader;
	unsigned int quadVAO;
	// initializes and configures quad buffer and vertex attributes
	void initRenderData();
};


#endif