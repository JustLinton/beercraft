#ifndef F3_H
#define F3_H

#include <iostream>
#include <map>
#include <string>

#include <beercraft/root_context.h>
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

    void render()
    {
        if(!isOn)
            return;
        
        rootContext->shaders["text"]->use();
        RenderText(*rootContext->shaders["text"], version_string, 15.0f, (float)SCR_HEIGHT - 30.0f, 0.38f, glm::vec3(1.0f, 1.0f, 1.0f));
    }

    string updateFPSData(const float *deltaTime, const float *accTime)
    {
        // this function should be called by main.cpp on every frame to ensure its properly work.
        static float lastTime = 0.0f;
        static string lastFpsStr = "0.0";
        static float lastFpsOneSec = 0.0f;
        static int lastFpsDataCountOneSec = 0;
        float fps = 1.0f / *deltaTime;
        lastFpsOneSec += fps;
        lastFpsDataCountOneSec += 1;
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
        return lastFpsStr;
    }

};





void renderTextCamPosition(){
    string res, tmp;
    stringstream sst;
    res += "Position> ";
    res += float2Str<float>(&(rootContext->camera->Position.x),&sst);
    res += ", ";
    res += float2Str<float>(&(rootContext->camera->Position.y),&sst);
    res += ", ";
    res += float2Str<float>(&(rootContext->camera->Position.z),&sst);
    rootContext->shaders["text"]->use();
    RenderText(*rootContext->shaders["text"], res, 15.0f, (float)SCR_HEIGHT - 80.0f, 0.38f, glm::vec3(1.0f, 1.0f, 1.0f));
}

void renderTextTest(){
    // rootContext->shaders["base_2d_shader"]->use();
    // renderBase2D(*rootContext->shaders["base_2d_shader"], 0.0f, (float)SCR_HEIGHT - 105.0f, 0.38f, glm::vec3(1.0f, 1.0f, 1.0f));
}

#endif