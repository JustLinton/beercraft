#ifndef ITMSLT_H
#define ITMSLT_H

#include <iostream>
#include <map>
#include <string>

#include <beercraft/context/render_context.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>

#include <bits/stdc++.h>
using namespace std;

class GUIItemSlot
{
public:
    RenderContext *renderContext;
    unsigned int localVAO, localVBO;
    float thickness;
    float size;
    float xpos = (float)SCR_WIDTH / 2;
    float ypos = (float)SCR_HEIGHT / 2;
    glm::vec4 color;
    GUIItemSlot(RenderContext *renderContext_, float thick, float sz, glm::vec4 theColor) : renderContext(renderContext_), thickness(thick), size(sz)
    {
        color = theColor;

        // configure opengl state for text-render
        // -----------------------------
        glEnable(GL_CULL_FACE);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(SCR_WIDTH), 0.0f, static_cast<float>(SCR_HEIGHT));
        renderContext->shaders["base2d2"]->use();
        glUniformMatrix4fv(glGetUniformLocation(renderContext->shaders["base2d2"]->ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

        // initFreeType();

        // create VAO and VBO
        // -----------------------------------
        glGenVertexArrays(1, &localVAO);
        glGenBuffers(1, &localVBO);
        glBindVertexArray(localVAO);
        glBindBuffer(GL_ARRAY_BUFFER, localVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 13 * 2, NULL, GL_STATIC_DRAW);
        // if want to re-draw it at sometime, use the following:
        //  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 13 * 4, NULL, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(0);

        // 给shader传参数：即in的那几个，这里是offset=0的那个in的参数
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void build()
    {
        // activate corresponding render state
        renderContext->shaders["base2d2"]->use();
        // glUniform3f(glGetUniformLocation(shader.ID, "textColor"), color.x, color.y, color.z);

        // bind
        glBindVertexArray(localVAO);
        glBindBuffer(GL_ARRAY_BUFFER, localVBO);

        // define vertices
        float vertices[13][2] = {
            {xpos - size, ypos + thickness},
            {xpos - size, ypos - thickness},
            {xpos + size, ypos - thickness},

            {xpos - size, ypos + thickness},
            {xpos + size, ypos - thickness},
            {xpos + size, ypos + thickness},

            {xpos - thickness, ypos + size},
            {xpos + thickness, ypos - size},
            {xpos + thickness, ypos + size},

            {xpos - thickness, ypos - size},
            {xpos + thickness, ypos - size},
            {xpos - thickness, ypos + size},

            // {xpos - size, ypos, 1.0f, 1.0f},

        };

        // make VBO
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // be sure to use glBufferSubData and not glBufferData

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void render()
    {
        // activate corresponding render state
        renderContext->shaders["base2d2"]->use();

        // 给shader传参数：即uniform的那几个，这里是inputColor的那个uniform
        glUniform4f(glGetUniformLocation(renderContext->shaders["base2d2"]->ID, "inputColor"), color.x, color.y, color.z, color.w);

        glBindVertexArray(localVAO);
        glBindBuffer(GL_ARRAY_BUFFER, localVBO);

        // render quad
        glDrawArrays(GL_TRIANGLES, 0, 13);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }
};

#endif