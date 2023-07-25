#ifndef F3_H
#define F3_H

#include <iostream>
#include <map>
#include <string>

#include <beercraft/context/render_context.h>
#include <beercraft/player.h>
#include <beercraft/font.h>
#include <beercraft/utils.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>

#include <bits/stdc++.h>
using namespace std;

class F3Debug{
public:
    unsigned int displayMode = 0;
    bool isOn = false;
    Player* player;
    RenderContext *renderContext;

    //number of f3 displaymodes.
    const int modeCount = 4;

    //this bool ensures f3key works properly. (add colddown using fpsdata update.)
    bool shouldProcessToggle = true;

    //fps Statistics
    float lastTime = 0.0f;
    string lastFpsStr = "0.0";
    float lastFpsOneSec = 0.0f;
    int lastFpsDataCountOneSec = 0;
    // end of fps Statistics

    // position Statistics
    string positionStrAcc = "Position> Loading...";
    // end of position Statistics

    // test output
    string testStr = "Test> Loading...";
    //end of test output

    F3Debug(RenderContext *renderContext_, Player *player_) : renderContext(renderContext_), player(player_)
    {}

    void toggle(){
        if(!shouldProcessToggle)
            return;
        isOn = !isOn;
        shouldProcessToggle = false;
    }

    void modeSwitch(){
        if (!shouldProcessToggle)
            return;
        if(!isOn)
            return;
        displayMode = (displayMode + 1) % modeCount;
        shouldProcessToggle = false;
    }

    void render()
    {
        if(!isOn)
            return;

        renderContext->shaders["text"]->use();

        string res = version_string;
        switch (displayMode)
        {
        case 0:
            res = version_string;
            break;

        case 2:
            res = lastFpsStr;
            break;

        case 1:
            res = positionStrAcc;
            break;

        case 3:
            res = testStr;
            break;

        default:
            res = version_string;
            break;
        }

        RenderText(*(renderContext->shaders["text"]), res, 15.0f, (float)SCR_HEIGHT - 30.0f, 0.38f, glm::vec3(1.0f, 1.0f, 1.0f));
    }

    void updateFPSData(const float *deltaTime, const float *accTime)
    {
        // this function should be called by main.cpp on every frame to ensure its properly work. (even if f3 is not on.)
        float fps = 1.0f / *deltaTime;
        lastFpsOneSec += fps;
        lastFpsDataCountOneSec += 1;

        if (*accTime - lastTime >= 1.0f)
        {
            shouldProcessToggle = true;
        }

        if (*accTime - lastTime >= 1.0f)
        {
            lastTime = *accTime;
            stringstream sst;
            sst << lastFpsOneSec / lastFpsDataCountOneSec;
            sst >> lastFpsStr;
            lastFpsOneSec = 0.0f;
            lastFpsDataCountOneSec = 0;
            lastFpsStr = "FPS> " + lastFpsStr;            
        }

        updateF3DataCamPosition();
    }

    void updateF3DataCamPosition()
    {
        //save energy if f3 is not on.
        if(!isOn)
            return;

        string res;
        stringstream sst;
        res += "Position> ";
        res += float2Str<float>(player->camera->Position.x, &sst);
        res += ", ";
        res += float2Str<float>(player->camera->Position.y, &sst);
        res += ", ";
        res += float2Str<float>(player->camera->Position.z, &sst);
        positionStrAcc = res;
    }

    void updateTestOutput(){
        string res;
        stringstream sst;
        res += "Test> ";
        res += float2Str<float>((int)(player->camera->Position.x), &sst);

        testStr = res;
    }
};







// void renderTextTest(){
//     // rootContext->shaders["base_2d_shader"]->use();
//     // renderBase2D(*rootContext->shaders["base_2d_shader"], 0.0f, (float)SCR_HEIGHT - 105.0f, 0.38f, glm::vec3(1.0f, 1.0f, 1.0f));
// }

#endif