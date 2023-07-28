#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <map>
#include <string>

#include <beercraft/context/root_context.h>
#include <beercraft/player.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>

#include <bits/stdc++.h>
using namespace std;

static float lastX = SCR_WIDTH / 2.0f;
static float lastY = SCR_HEIGHT / 2.0f;
static bool firstMouse = true;

// frame timing
static float deltaTime = 0.0f;
static float lastFrame = 0.0f;

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    // if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
        rootContext->player->moveBackToSpawnPoint();

    //f3 debug
    if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
        rootContext->beerCraftGUI->f3Debug->toggle();
    if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
        rootContext->beerCraftGUI->f3Debug->modeSwitch();
    // end of f3 debug

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        rootContext->player->ProcessControl(PLAYER_FLY_UP, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        rootContext->player->ProcessControl(PLAYER_FLY_DOWN, deltaTime);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        rootContext->player->ProcessControl(PLAYER_SPECT_FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        rootContext->player->ProcessControl(PLAYER_SPECT_BACK, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        rootContext->player->ProcessControl(PLAYER_SPECT_LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        rootContext->player->ProcessControl(PLAYER_SPECT_RIGHT, deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow *window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    rootContext->player->camera->ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    rootContext->player->camera->ProcessMouseScroll(static_cast<float>(yoffset));
}

#endif