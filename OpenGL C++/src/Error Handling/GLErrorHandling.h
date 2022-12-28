#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLErrorHandling::GLClearError();\
	x;\
	ASSERT(GLErrorHandling::GLLogCall(#x, __FILE__, __LINE__))

class GLErrorHandling
{
public:
	static void GLClearError();
	static bool GLLogCall(const char* function, const char* file, int line);
};

