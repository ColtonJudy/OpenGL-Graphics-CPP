#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../Error Handling/GLErrorHandling.h"

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
public:
	static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	static ShaderProgramSource ParseShader(const std::string& filepath);
private:
	static unsigned int CompileShader(unsigned int type, const std::string& source);
};

