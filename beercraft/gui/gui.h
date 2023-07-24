#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <map>
#include <string>

#include <beercraft/root_context.h>
#include <beercraft/gui/crosshair.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>

#include <bits/stdc++.h>
using namespace std;

class BeerCraftGUI{
public:
    GUICrossHair* crossHair;

    BeerCraftGUI(){
        crossHair = new GUICrossHair(1.0f, 8.35f, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        crossHair->build();
    }

    void render(){
        crossHair->render();
    }
};

#endif