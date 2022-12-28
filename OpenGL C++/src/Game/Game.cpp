#include "Game.h"

Game::Game(int initialWindowWidth, int initialWindowHeight, const char* initialWindowTitle)
{
	this->initialWindowWidth = initialWindowWidth;
	this->initialWindowHeight = initialWindowHeight;
	this->initialWindowTitle = initialWindowTitle;
}

void Game::Run()
{
	Initialize();
	
	DisplayManager::CreateWindow(initialWindowWidth, initialWindowHeight, initialWindowTitle);

	LoadContent();

	while (!glfwWindowShouldClose(DisplayManager::window)) {
		Update();

		//keeps windows from saying the program is not responding
		glfwPollEvents();

		Render();
	}

	DisplayManager::CloseWindow();
}

void Game::Initialize(){}
void Game::LoadContent(){}
void Game::Update(){}
void Game::Render(){}