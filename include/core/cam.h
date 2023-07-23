#ifndef CAM_H
#define CAM_H

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
#include <graphics/camera.h>

#include <bits/stdc++.h>
using namespace std;

void cam(RootContext* rootContext, Camera* camera){
    // don't forget to enable shader before setting uniforms
    rootContext->shaders["default_model"]->use();

    // view/projection transformations
    glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    glm::mat4 view = camera->GetViewMatrix();
    rootContext->shaders["default_model"]->setMat4("projection", projection);
    rootContext->shaders["default_model"]->setMat4("view", view);
}

void renderBlocks(RootContext* rootContext){
    // render the loaded model
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
    model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));     // it's a bit too big for our scene, so scale it down
    rootContext->shaders["default_model"]->setMat4("model", model);
    rootContext->blockModels[2]->Draw(*rootContext->shaders["default_model"]);
}

void renderTexts(RootContext* rootContext){
    rootContext->shaders["text"]->use();
    RenderText(*rootContext->shaders["text"], version_string, 15.0f, (float)SCR_HEIGHT - 30.0f, 0.38f, glm::vec3(1.0f, 1.0f, 1.0f));
}

#endif