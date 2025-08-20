#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Game.h"
#include "GameConstants.h"
#include "InputManager.h"
#include "ResourceManager.h"

#include <chrono>
#include <iostream>
#include <thread>

#define FRAME_LIMITING 1


// GLFW function declarations
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);


int main(int argc, char* argv[])
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindowHint(GLFW_RESIZABLE, false);

#pragma warning( push )
#pragma warning( disable : 4244 )
    GLFWwindow* window = glfwCreateWindow(GameConstants::PlayableX, GameConstants::PlayableY, "Space Invaders", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetWindowPos(window, 10, 50);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // OpenGL configuration
    // --------------------
    glViewport(0, 0, GameConstants::PlayableX, GameConstants::PlayableY);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
#pragma warning( pop )
    
    // initialize game
    // ---------------
    Game SpaceInvaders;

    // deltaTime variables
    // -------------------
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    constexpr float TargetFrameTime = 1.0f / 60.0f;

    float fpsTimer = 0.0f;
    unsigned int FrameCounter = 0;

    while (!glfwWindowShouldClose(window))
    {
        // calculate delta time
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glfwPollEvents();

        fpsTimer += deltaTime;
        FrameCounter++;

        if (fpsTimer >= 1.0f) // every second
        {
            std::cout << "FPS: " << FrameCounter << std::endl;
            FrameCounter = 0;
            fpsTimer = 0.0f;
        }

        // manage user input
        // -----------------
        SpaceInvaders.ProcessInput(deltaTime);

        // update game state
        // -----------------
        SpaceInvaders.Update(deltaTime);

        // render
        // ------
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        SpaceInvaders.Render();
        glfwSwapBuffers(window);
#if FRAME_LIMITING
        // wait for next frame
        float TimeSpent = static_cast<float>(glfwGetTime()) - currentFrame;
        float TimeLeft = std::max(0.0f, TargetFrameTime - TimeSpent) / 3.0f;
        if (TimeLeft > 0)
        {
            std::this_thread::sleep_for(std::chrono::duration<float>(TimeLeft));
        }
#endif
    }
    // delete all resources as loaded using the resource manager
    // ---------------------------------------------------------
    ResourceManager::Clear();

    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    // when a user presses the escape key, we set the WindowShouldClose property to true, closing the application
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
            InputManager::Get().keys[key] = true;
        else if (action == GLFW_RELEASE)
            InputManager::Get().keys[key] = false;
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}