#ifndef CRSHR_H
#define CRSHR_H

#include <iostream>
#include <map>
#include <string>

#include <beercraft/root_context.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>

#include <bits/stdc++.h>
using namespace std;

class GUICrossHair{
public:
    Shader shader;
    unsigned int localVAO, localVBO;
    float thickness;
    float size;
    float xpos = (float)SCR_WIDTH / 2;
    float ypos = (float)SCR_HEIGHT / 2;
    glm::vec4 color;
    GUICrossHair(float thick, float sz, glm::vec4 theColor) : shader("./shaders/base2d2.vs", "./shaders/base2d2.fs"), thickness(thick), size(sz)
    {
        color = theColor;

        // configure opengl state for text-render
        // -----------------------------
        glEnable(GL_CULL_FACE);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(SCR_WIDTH), 0.0f, static_cast<float>(SCR_HEIGHT));
        shader.use();
        glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

        // initFreeType();

        // create VAO and VBO
        // -----------------------------------
        glGenVertexArrays(1, &localVAO);
        glGenBuffers(1, &localVBO);
        glBindVertexArray(localVAO);
        glBindBuffer(GL_ARRAY_BUFFER, localVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 13 * 4, NULL, GL_STATIC_DRAW);
        //if want to re-draw it at sometime, use the following:
        // glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 13 * 4, NULL, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void build()
    {
        // activate corresponding render state
        shader.use();
        // glUniform3f(glGetUniformLocation(shader.ID, "textColor"), color.x, color.y, color.z);

        //bind
        glBindVertexArray(localVAO);
        glBindBuffer(GL_ARRAY_BUFFER, localVBO);

        // define vertices
        float vertices[13][4] = {
            {xpos - size, ypos + thickness, 0.0f, 0.0f},
            {xpos - size, ypos - thickness, 0.0f, 1.0f},
            {xpos + size, ypos - thickness, 1.0f, 1.0f},

            {xpos - size, ypos + thickness, 1.0f, 1.0f},
            {xpos + size, ypos - thickness, 0.0f, 1.0f},
            {xpos + size, ypos + thickness, 0.0f, 0.0f},

            {xpos - thickness, ypos + size, 1.0f, 1.0f},
            {xpos + thickness, ypos - size, 1.0f, 1.0f},
            {xpos + thickness, ypos + size, 1.0f, 1.0f},

            {xpos - thickness, ypos - size, 1.0f, 1.0f},
            {xpos + thickness, ypos - size, 1.0f, 1.0f},
            {xpos - thickness, ypos + size, 1.0f, 1.0f},

            // {xpos - size, ypos, 1.0f, 1.0f},

        };

        //make VBO
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // be sure to use glBufferSubData and not glBufferData

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void render()
    {
        // activate corresponding render state
        shader.use();
        // glUniform3f(glGetUniformLocation(shader.ID, "textColor"), color.x, color.y, color.z);

        glUniform4f(glGetUniformLocation(shader.ID, "inputColor"), color.x, color.y, color.z,color.w);

        glBindVertexArray(localVAO);
        glBindBuffer(GL_ARRAY_BUFFER, localVBO);

        // render quad
        glDrawArrays(GL_TRIANGLES, 0, 13);

       
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }
};

#endif