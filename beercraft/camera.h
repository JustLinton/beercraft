#ifndef CAM_H
#define CAM_H

#include <iostream>
#include <map>
#include <string>

#include <beercraft/root_context.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>
#include <graphics/camera.h>

#include <bits/stdc++.h>
using namespace std;

// void initCamera(){
//     static Camera camera(glm::vec3(0.0f, 1.0f, 0.0f));
//     rootContext->camera = &camera;
// }

void cameraLookAt(){
    // don't forget to enable shader before setting uniforms
    rootContext->shaders["default_model"]->use();

    // view/projection transformations
    glm::mat4 projection = glm::perspective(glm::radians(rootContext->camera->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    glm::mat4 view = rootContext->camera->GetViewMatrix();
    rootContext->shaders["default_model"]->setMat4("projection", projection);
    rootContext->shaders["default_model"]->setMat4("view", view);
}

void moveBackToSpawnPoint(){
    rootContext->camera->Position = glm::vec3(0.0f, 1.0f, 0.0f);
}

void renderBlocks(){
    
    rootContext->shaders["default_model"]->use();

    // render the loaded model
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
    model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));     // it's a bit too big for our scene, so scale it down
    rootContext->shaders["default_model"]->setMat4("model", model);
    rootContext->blockModels[2]->Draw(*rootContext->shaders["default_model"]);
}


#endif