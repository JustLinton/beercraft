#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <map>
#include <string>

#include <beercraft/context/render_context.h>
#include <beercraft/player.h>
#include <beercraft/gui/crosshair.h>
#include <beercraft/gui/f3.h>

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
    F3Debug* f3Debug;

    Player* player;
    RenderContext *renderContext;

    BeerCraftGUI(RenderContext *renderContext_, Player *player_) : renderContext(renderContext_), player(player_)
    {
        crossHair = new GUICrossHair(renderContext, 1.0f, 8.35f, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        crossHair->build();

        f3Debug = new F3Debug(renderContext,player);
    }

    void render(){
        crossHair->render();
        f3Debug->render();
    }
};

#endif