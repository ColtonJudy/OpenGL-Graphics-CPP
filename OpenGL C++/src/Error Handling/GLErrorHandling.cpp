#include "GLErrorHandling.h"

void GLErrorHandling::GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLErrorHandling::GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (0x0" << std::hex << error << std::dec << "): " << function << " " << file << " ln " << line << std::endl;
		return false;
	}
	return true;
}
