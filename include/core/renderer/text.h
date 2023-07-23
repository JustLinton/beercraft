#ifndef TEXT_RENDER_H
#define TEXT_RENDER_H

#include <iostream>
#include <map>
#include <string>

#include <core/root_context.h>
#include <core/font.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>

#include <bits/stdc++.h>
using namespace std;

void renderTexts(RootContext *rootContext){
    rootContext->shaders["text"]->use();
    RenderText(*rootContext->shaders["text"], version_string, 15.0f, (float)SCR_HEIGHT - 30.0f, 0.38f, glm::vec3(1.0f, 1.0f, 1.0f));
}

#endif