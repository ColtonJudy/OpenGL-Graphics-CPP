#pragma once
#include <iostream>
#include <string>
#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include "../Rendering/Display/DisplayManager.h"
#include "../Rendering/Shaders/Shader.h"
#include "../Error Handling/GLErrorHandling.h"
#include "../VertexBuffer.h"
#include "../IndexBuffer.h"


class Game 
 {

public:
	Game(int screenWidth, int screenHeight, const char* title);
	void Run();

protected:
	int initialWindowWidth;
	int initialWindowHeight;
	const char* initialWindowTitle;

	virtual void Initialize();
	virtual void LoadContent();
	virtual void Update();
	virtual void Render();
};