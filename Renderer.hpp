#pragma once
#include <GLFW/glfw3.h>
#include "Mesh.hpp"
#include <vector>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;


class Renderer
{
public:
#pragma region Constructors
	Renderer() {
		std::vector<Vertex> vertices = {
			{{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
			{{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
			{{0.0f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.5f, 1.0f}}
		};
		std::vector<unsigned int> indices = { 0, 1, 2 };

		auto wd = fs::current_path();
		auto shaders_dir("assets/shaders");
		auto shaders_path = wd / shaders_dir;

		auto vert_shader = shaders_path / fs::path("refraction.vert");
		auto frag_shader = shaders_path / fs::path("refraction.frag");

		testshader = Shader(vert_shader.generic_string(), frag_shader.generic_string());

		testmesh = new Mesh(vertices, indices, std::vector<Texture>());
	}
	~Renderer() {
		delete testmesh;
	}
	
#pragma endregion

	void Clear() {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void Render() {
		testmesh->Draw(testshader);
	}

private:
	Shader testshader;
	Mesh* testmesh;
};

