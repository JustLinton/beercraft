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
#include <beercraft/player.h>
#include <beercraft/context/render_context.h>


#include <bits/stdc++.h>
using namespace std;

class RootContext{
public:
    RenderContext* renderContext;

    Player* player;
    BeerCraftGUI* beerCraftGUI;

    RootContext(){
        renderContext = new RenderContext;
        player = new Player(renderContext);
        beerCraftGUI = new BeerCraftGUI(renderContext,player);
    }
};

static RootContext *rootContext;

#endif