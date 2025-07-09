#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Game.h"
#include "ResourceManager.h"

#include <iostream>


// foward declares
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// globals
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

Game SpaceInvaders(SCREEN_WIDTH, SCREEN_HEIGHT);

int main(int argc, char* argv[])
{
	// intialize and configure window
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, false);
	// create window
	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Invaders", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// initialize and configure GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD";
		return -1;
	}
	glfwSetKeyCallback(window, key_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC1_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// initialize game
	SpaceInvaders.Init();
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	// game loop
	while (!glfwWindowShouldClose(window))
	{
		// calculate delta time
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();
		// manage user input
		SpaceInvaders.ProcessInput(deltaTime);
		// update game state
		SpaceInvaders.Update(deltaTime);
		// render
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		SpaceInvaders.Render();
		glfwSwapBuffers(window);
	}

	// clean up
	ResourceManager::Clear();
	glfwTerminate();

	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// exit on Esc
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			SpaceInvaders.Keys[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			SpaceInvaders.Keys[key] = false;
		}
	}
}