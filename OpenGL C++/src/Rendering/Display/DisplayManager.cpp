#include "DisplayManager.h"

GLFWwindow* DisplayManager::window;
Vector2 DisplayManager::windowSize;

void DisplayManager::CreateWindow(int width, int height, const char* title)
{
	windowSize = Vector2(width, height);

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_FOCUSED, true);
	glfwWindowHint(GLFW_RESIZABLE, false);

	window = glfwCreateWindow(width, height, title, NULL, NULL);

	//something has gone wrong
	if (window == NULL)
		return;

	int monitorW = 0;
	int monitorH = 0;

	glfwGetMonitorWorkarea(glfwGetPrimaryMonitor(), NULL, NULL, &monitorW, &monitorH);

	int xPos, yPos;

	xPos = (int)(monitorW - width) / 2;
	yPos = (int)(monitorH - height) / 2;

	glfwSetWindowPos(window, xPos, yPos);

	glfwMakeContextCurrent(window);
	
	//initialize GLEW
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW failed to initialize" << std::endl;
	}
	
	std::cout << glGetString(GL_VERSION) << std::endl;

	glViewport(0, 0, width, height);
	glfwSwapInterval(0); //vsync is on
}

void DisplayManager::CloseWindow()
{
	glfwTerminate();
}
