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
#include <beercraft/context/game_context.h>
#include <beercraft/renderer/block_renderer.h>

#include <bits/stdc++.h>
using namespace std;

class RootContext{
public:
    RenderContext* renderContext;
    GameContext* gameContext;

    Player* player;
    BeerCraftGUI* beerCraftGUI;
    BlockRenderer* blockRenderer;

    RootContext(){
        renderContext = new RenderContext;
        player = new Player(renderContext);
        beerCraftGUI = new BeerCraftGUI(renderContext,player);

        gameContext = new GameContext(renderContext);
        blockRenderer = new BlockRenderer(renderContext,gameContext);
    }
};

static RootContext *rootContext;

#endif