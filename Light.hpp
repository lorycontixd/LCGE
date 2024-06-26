#pragma once

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.hpp"

#include <string>
#include <vector>

class Light
{
public:
    unsigned int VAO;
    Light()
    {
        //setupMesh();
    }

    void drawCube(Shader& shader, glm::vec3 pos, glm::vec3 color, glm::mat4 projection, glm::mat4 view, glm::mat4 model)
    {
        shader.setMat4("projection", projection);
        shader.setMat4("view", view);
        model = glm::mat4(1.0f);
        model = glm::translate(model, pos);
        // model = glm::scale(model, glm::vec3(0.2f));
        shader.setMat4("model", model);
        shader.setVec3("color", color);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }

private:
    unsigned int VBO;

    /*void setupMesh()
    {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, 288 * sizeof(float), &light_vertices[0], GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));

        glBindVertexArray(0);
    }
    */
};