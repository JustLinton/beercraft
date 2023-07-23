#ifndef LINTON_MODELS_H
#define LINTON_MODELS_H

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
#include <graphics/model.h>

#include <bits/stdc++.h>
using namespace std;

void initModels()
{
    // load models
    // -----------
    static Model b2("objects/blocks/grass_block/block.obj");
    rootContext->blockModels[2] = &b2;
}

#endif