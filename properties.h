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

// ----------------------- screen size ----------------------------------------------
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;
// ==================================================================================

// ----------------------- draw in wireframe ----------------------------------------
const bool WIREFRAME = false;
// ==================================================================================

// ------------------------------ version string--- ---------------------------------
const string version_string = "Beercraft  Alpha  Build";
// ==================================================================================

// ----------------------- Color of default sky -------------------------------------
glm::vec4 SKY_COLOR = glm::vec4(0.713f, 0.839f, 0.984f, 1.0f);
// ==================================================================================

// ------------------------------ initial font path ---------------------------------
const string font_path = "./fonts/Minecraft.ttf";
// ==================================================================================

// ----------------------- initial block model path ---------------------------------
const string default_model_path = "./objects/blocks/grass_block/block.obj";
// string backpack_text_path = "./objects/blocks/chest/chest.obj";
// string backpack_text_path = "./objects/door/Wooden-Door.obj";
// ==================================================================================

// ----------------------- tell stb_image.h to flip loaded texture's on the y-axis.--
const bool TEXTURE_Y_FLIP = false;
// ==================================================================================

#endif