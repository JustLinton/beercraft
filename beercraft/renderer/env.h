#ifndef ENV_RENDER_H
#define ENV_RENDER_H

#include <iostream>
#include <map>
#include <string>

#include <beercraft/root_context.h>
#include <beercraft/font.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>

#include <bits/stdc++.h>
using namespace std;

void renderSkyColor()
{
    glClearColor(SKY_COLOR.x, SKY_COLOR.y, SKY_COLOR.z, SKY_COLOR.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

#endif