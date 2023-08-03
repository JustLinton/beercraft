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

enum PlayerSpeed{
    PLAYER_SPEED_FLY
};

class Velocity{
public:
    void update();
    float speed;
    glm::vec3 whole = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 physics = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 movement = glm::vec3(0.0f, 0.0f, 0.0f);
};

class Player{
public:
    Camera* camera;
    glm::vec3 spawnPoint = glm::vec3(0.0f, 0.0f, 0.0f);
    RenderContext* renderContext;

    Player(RenderContext *renderContext_) : renderContext(renderContext_)
    {
        camera = new Camera(spawnPoint);
        initCameraVision();
    }

    void moveBackToSpawnPoint()
    {
        position = glm::vec3(0.0f, 0.0f, 0.0f);
    }

    float getSpeed(){
        return velocity.speed;
    }

    Velocity* getVelocity(){
        return &velocity;
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
    void updatePosition();

private:
    // walkMaxSpeed: 行走最大速度。为防止斜着走比直着走快，不允许movementspeed超过该速度。如果阻力过大但是行走加速度过小，则导致无法达到该最大速度。
    float walkMaxSpeed = 0.15f; // default:2.5f mc:5.5f.

    // walkAccelerate: 行走加速度。越高则越灵敏，越低则越能感觉出惯性。其数值需与阻力数值匹配。
    float walkAccelerate = 0.33f;
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    Velocity velocity;
    void move(PlayerSpeed speedType, glm::vec3 vv);
};

void Player::ProcessControl(PlayerMovement movement, float deltaTime)
{
        float frameAcc = walkAccelerate * deltaTime;

        switch (movement)
        {
        case PLAYER_SPECT_FORWARD:
            move(PLAYER_SPEED_FLY, camera->Front * frameAcc);
        break;

        case PLAYER_SPECT_BACK:
            move(PLAYER_SPEED_FLY, -camera->Front * frameAcc);
            break;

        case PLAYER_SPECT_LEFT:
            move(PLAYER_SPEED_FLY, -camera->Right * frameAcc);
            break;

        case PLAYER_SPECT_RIGHT:
            move(PLAYER_SPEED_FLY, camera->Right * frameAcc);
            break;

        case PLAYER_FLY_UP:
            move(PLAYER_SPEED_FLY, glm::vec3(0.0f, 1.0f, 0.0f) * frameAcc);
            break;

        case PLAYER_FLY_DOWN:
            move(PLAYER_SPEED_FLY, -glm::vec3(0.0f, 1.0f, 0.0f) * frameAcc);
            break;

        case PLAYER_FLY_FORWARD:
            move(PLAYER_SPEED_FLY, glm::vec3(-1.0f, 0.0f, -1.0f) * glm::normalize(glm::cross(camera->Right, camera->WorldUp)) * frameAcc);
            break;

        case PLAYER_FLY_BACK:
            move(PLAYER_SPEED_FLY, -glm::vec3(-1.0f, 0.0f, -1.0f) * glm::normalize(glm::cross(camera->Right, camera->WorldUp)) * frameAcc);
            break;

        default : 
            break;
        }
}

void Player::move(PlayerSpeed speedType, glm::vec3 vv)
{
    glm::vec3 res = velocity.movement;

    if(speedType == PLAYER_SPEED_FLY){
        res += vv;

        float newSpeed = glm::length(res);
        if(newSpeed >= walkMaxSpeed){
            float oldNewRatio = (float)walkMaxSpeed / newSpeed;
            res *= glm::vec3(oldNewRatio, oldNewRatio, oldNewRatio);
        }
    }

    velocity.movement = res;
}


//阻力。为分段函数。当0.05以上时，采用简化版的物理公式，否则采用一次函数。
float airResistanceCoefficient = 0.44f;
float calResistanceAcc(float speed){
    if(speed >= 0.05)
        return 0.5 * airResistanceCoefficient * speed;
    return 0.05;
}

glm::vec3 resist(glm::vec3 v)
{
    glm::vec3 res = v - v * calResistanceAcc(glm::length(v));
    if (res.x * v.x < 0)
        res.x = 0;
    if (res.y * v.y < 0)
        res.y = 0;
    if (res.z * v.z < 0)
        res.z = 0;
    return res;
}

void Velocity::update()
{
    glm::vec3 res = glm::vec3(0.0f,0.0f,0.0f);

    res += movement;

    whole = res;
    speed = glm::length(whole);

    movement = resist(movement);
    whole = resist(whole);
}

void Player::updatePosition()
{
    position += velocity.whole;
    // height of steve is 1.62.
    camera->Position = position + glm::vec3(0.0f, 1.62f, 0.0f);
}

#endif