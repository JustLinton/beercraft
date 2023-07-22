#ifndef CFG_H
#define CFG_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader_m.h>
#include <graphics/camera.h>
#include <graphics/model.h>

#include <bits/stdc++.h>
using namespace std;

// ======================= screen size ========
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;
// ============================================

// ======================= draw in wireframe===
const unsigned bool WIREFRAME = false;
// ============================================

// ======================= Color of default sky
glm::vec4 SKY_COLOR = glm::vec4(0.713f, 0.839f, 0.984f, 1.0f);
// ============================================



#endif