#define STB_IMAGE_IMPLEMENTATION

#include "properties.h"
#include <beercraft/font.h>
#include <beercraft/context/root_context.h>
#include <beercraft/models.h>
#include <beercraft/player.h>
#include <beercraft/control.h>

#include <beercraft/renderer/env.h>
#include <beercraft/gui/gui.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader_m.h>
#include <graphics/camera.h>
#include <graphics/model.h>

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

#include <bits/stdc++.h>
using namespace std;

void initRootContext();

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Beercraft", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    stbi_set_flip_vertically_on_load(TEXTURE_Y_FLIP);

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    initRootContext();

    if (WIREFRAME)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // render
        // ------
        renderSkyColor();
        rootContext->player->initCameraVision();
        rootContext->player->renderBlocks();
        rootContext->beerCraftGUI->f3Debug->updateFPSData(&deltaTime, &currentFrame);
        rootContext->beerCraftGUI->f3Debug->updateTestOutput();
        rootContext->beerCraftGUI->render();
        
        // renderTextTest();

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

void initRootContext()
{
    rootContext = new RootContext;
    initModels();
    // initCamera();
}
