#pragma once
#include "Game/Game.h"

class TestGame : public Game
{
	using Game::Game;

	unsigned int buffer;
	unsigned int vao;
	IndexBuffer* ib;
	unsigned int shader;

	virtual void Initialize();
	virtual void LoadContent();
	virtual void Update();
	virtual void Render();
};

