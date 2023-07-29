#ifndef CAM_H
#define CAM_H

#include <iostream>
#include <map>
#include <string>

#include <beercraft/context/render_context.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>
#include <graphics/camera.h>

#include <bits/stdc++.h>
using namespace std;

enum PlayerMovement
{
    PLAYER_SPECT_FORWARD,
    PLAYER_SPECT_BACK,
    PLAYER_SPECT_LEFT,
    PLAYER_SPECT_RIGHT,
    PLAYER_FLY_UP,
    PLAYER_FLY_DOWN,
    PLAYER_FLY_FORWARD,
    PLAYER_FLY_BACK
};

class Player{
public:
    Camera* camera;
    glm::vec3 spawnPoint = glm::vec3(0.0f, 1.0f, 0.0f);
    RenderContext* renderContext;

    Player(RenderContext *renderContext_) : renderContext(renderContext_)
    {
        camera = new Camera(spawnPoint);
        initCameraVision();
    }

    void moveBackToSpawnPoint()
    {
        camera->Position = glm::vec3(0.0f, 1.0f, 0.0f);
    }

    void initCameraVision()
    {
        // don't forget to enable shader before setting uniforms
        renderContext->shaders["default_model"]->use();

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera->GetViewMatrix();
        renderContext->shaders["default_model"]->setMat4("projection", projection);
        renderContext->shaders["default_model"]->setMat4("view", view);
    }

    void ProcessControl(PlayerMovement movement, float deltaTime);

    private:
        float speed = 5.5f; //default:2.5f
};

void Player::ProcessControl(PlayerMovement movement, float deltaTime)
{
        float velocity = speed * deltaTime;

        switch (movement)
        {
        case PLAYER_SPECT_FORWARD:
            camera->Position += camera->Front * velocity;
            break;

        case PLAYER_SPECT_BACK:
            camera->Position -= camera->Front * velocity;
            break;

        case PLAYER_SPECT_LEFT:
            camera->Position -= camera->Right * velocity;
            break;

        case PLAYER_SPECT_RIGHT:
            camera->Position += camera->Right * velocity;
            break;

        case PLAYER_FLY_UP:
            camera->Position += glm::vec3(0.0f, 1.0f, 0.0f) * velocity;
            break;

        case PLAYER_FLY_DOWN:
            camera->Position -= glm::vec3(0.0f, 1.0f, 0.0f) * velocity;
            break;

        case PLAYER_FLY_FORWARD:
            camera->Position += glm::vec3(1.0f, 0.0f, 1.0f) * camera->Front * velocity;
            break;

        case PLAYER_FLY_BACK:
            camera->Position -= glm::vec3(1.0f, 0.0f, 1.0f) * camera->Front * velocity;
            break;

        default : 
            break;
        }
}

#endif