#ifndef LINTON_SHADERS_H
#define LINTON_SHADERS_H

#include <iostream>
#include <map>
#include <string>

#include <core/root_context.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>

#include <bits/stdc++.h>
using namespace std;

void initShaders()
{
    // build and compile shaders
    // -------------------------
    static Shader text_shader = initFontRender();
    rootContext->shaders["text"] = &text_shader;
    static Shader default_model_Shader("./shaders/1.model_loading.vs", "./shaders/1.model_loading.fs");
    rootContext->shaders["default_model"] = &default_model_Shader;
}

#endif