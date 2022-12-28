#pragma once
#include <iostream>
#include <string>
#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include "../../Utility/Vector2.h"

static class DisplayManager 
{
public:
	static GLFWwindow* window;
	static Vector2 windowSize;

	static void CreateWindow(int width, int height, const char* title);
	static void CloseWindow();

private:
	static GLFWmonitor* monitor;
};

