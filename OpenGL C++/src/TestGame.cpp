#include "TestGame.h"

void TestGame::Initialize()
{
}

void TestGame::LoadContent()
{
	float positions[] = {
		 -0.5f, -0.5f,
		  0.5f, -0.5f,
		  0.5f,  0.5f,
		 -0.5f,  0.5f,
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	GLCall(glGenVertexArrays(1, &vao));
	GLCall(glBindVertexArray(vao));

	VertexBuffer vb(positions, 4 * 2 * sizeof(float));

	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));

	ib = new IndexBuffer(indices, 6);
	
	ShaderProgramSource source = Shader::ParseShader("../OpenGL C++/res/Shaders/Basic.shader"); //../OpenGL C++/ is used because the shader file was failing to import on exe launch
	shader = Shader::CreateShader(source.VertexSource, source.FragmentSource);
	GLCall(glUseProgram(shader));

	//unbind buffers
	GLCall(glUseProgram(0));
	GLCall(glBindVertexArray(0));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}    

void TestGame::Update()
{
	//std::cout << "pain" << std::endl;
}

void TestGame::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	GLCall(glUseProgram(shader));

	//set the color
	GLCall(int location = glGetUniformLocation(shader, "u_Color"));
	ASSERT(location != -1);
	GLCall(glUniform4f(location, 0.0f, 1.0f, 0.0f, 1.0f));

	GLCall(glBindVertexArray(vao));
	ib->Bind();

	GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

	glfwSwapBuffers(DisplayManager::window);
}
     