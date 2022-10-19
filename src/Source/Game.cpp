#include "Game.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

Game::Game(const char* gameName, unsigned int width, unsigned int height)
{
    isRunning = false;
    this->gameName = gameName;
    this->width = width;
    this->height = height;
}

Game::~Game()
{
    isRunning = false;
    glfwDestroyWindow(window);
    glfwTerminate();
}

int Game::Initialise()
{
    if(InitialiseGLFW() == -1) return -1;
    if(CreateWindow() == -1) return -1;
    if(InitialiseGLEW() == -1) return -1;

    // TODO: Initialise stuff here

    isRunning = true;
    return 0;
}

void Game::Update()
{
    // TODO: Update stuff here
}

void Game::Render()
{
    glClearColor(0.528f, 0.880f, 0.839f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // TODO: Render stuff here

    glfwSwapBuffers(window);
}

void Game::HandleEvents()
{
    glfwPollEvents();
        
    if(glfwWindowShouldClose(window)) isRunning = false;
}

int Game::InitialiseGLFW()
{
    if (!glfwInit())
    {
        std::cout << "ERROR: Unable to initialise GLEW.\n";
        return -1;
    }

    // Set OpenGL version to 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    return 0;
}

int Game::CreateWindow()
{
    window = glfwCreateWindow(1280, 720, "Learning OpenGL", NULL, NULL);
    if (!window)
    {
        std::cout << "ERROR: Unable to create Window.\n";
        return -1;
    }

    glfwMakeContextCurrent(window);
    return 0;
}

int Game::InitialiseGLEW()
{
    if (glewInit() != GLEW_OK)
    {
        std::cout << "ERROR: Unable to initialize GLEW.\n";
        return -1;
    }
    return 0;
}
