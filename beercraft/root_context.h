#ifndef CTX_H
#define CTX_H

#include <iostream>
#include <map>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>
#include <graphics/model.h>
#include <graphics/camera.h>

#include <beercraft/gui/gui.h>

#include <bits/stdc++.h>
using namespace std;

class RootContext
{
public:
    unordered_map<string, Shader *> shaders;
    unordered_map<unsigned int, Model *> blockModels;
    
    unordered_map<string, unsigned int *> VAOs;
    unordered_map<string, unsigned int *> VBOs;

    Camera *camera;
    
    BeerCraftGUI* beerCraftGUI;

    RootContext(){
        camera = new Camera(glm::vec3(0.0f, 1.0f, 0.0f));
        beerCraftGUI = new BeerCraftGUI(camera);
    }
};

static RootContext *rootContext;

#endif