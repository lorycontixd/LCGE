#pragma once

#include <iostream>
#include <GLFW/glfw3.h>
#include "Renderer.hpp"

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

class LCGE
{
public:
#pragma region Constructors
	LCGE() {
		m_Width = 800;
		m_Height = 600;
		aspectRatio = (float)m_Width / m_Height;
		window = nullptr;
		renderer = nullptr;
	}
	LCGE(float width, float height) {
		this->m_Width = width;
		this->m_Height = height;
		this->aspectRatio = (float)m_Width / m_Height;
		window = nullptr;
		renderer = nullptr;
	}
	~LCGE() {
		Close();
	}
#pragma endregion

	

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	void Init() {
		
		// Initialise GLFW
		if (!glfwInit())
		{
			exit( EXIT_FAILURE );
		}
		glfwSetErrorCallback(error_callback);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		this->window = glfwCreateWindow(this->m_Width, this->m_Height, "My Title", NULL, NULL);
		if (!this->window)
		{
			std::cerr << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		glfwMakeContextCurrent(this->window);
		gladLoadGL();
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // resize

		this->renderer = new Renderer();
		this->is_initialized = true;
	}

	void Update() {
		if (!this->is_initialized) {
			std::cerr << "WARNING: Engine class hasn't been initialized, but you are trying to call a function. Expect the unexpected!" << std::endl;
		}
	}

	void Render() {
		if (!this->is_initialized) {
			std::cerr << "WARNING: Engine class hasn't been initialized, but you are trying to call a function. Expect the unexpected!" << std::endl;
		}
	}

	void ProcessEvents() {
		if (!this->is_initialized) {
			std::cerr << "WARNING: Engine class hasn't been initialized, but you are trying to call a function. Expect the unexpected!" << std::endl;
		}
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
	}

	void Run() {
		if (!this->is_initialized) {
			std::cerr << "WARNING: Engine class hasn't been initialized, but you are trying to call a function. Expect the unexpected!" << std::endl;
		}
		this->is_running = !glfwWindowShouldClose(this->window);
		while (this->is_running) {
			glfwGetFramebufferSize(window, &m_Width, &m_Height);

			this->ProcessEvents();
			this->renderer->Clear();
			this->renderer->Render();
			this->Update();
			this->Render();

			glfwSwapBuffers(this->window);
			glfwPollEvents();
		}
		this->Close();
	}

	void Close() {
		glfwDestroyWindow(this->window);
		glfwTerminate();
		exit(EXIT_SUCCESS);
	}
private:
	int m_Width, m_Height;
	float aspectRatio;

	bool is_running = false;
	bool is_initialized = false;
	GLFWwindow* window = NULL;
	Renderer* renderer;
};

