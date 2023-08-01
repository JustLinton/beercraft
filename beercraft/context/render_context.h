#ifndef RDRCTX_H
#define RDRCTX_H

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

#include <beercraft/logger.h>
#include <beercraft/texture.h>

#include <bits/stdc++.h>
using namespace std;

class RenderContext
{
public:
    unordered_map<string, Shader *> shaders;
    unordered_map<string, unsigned int> textures;

    RenderContext(){
        initShaders();
        initTextures();
    }

private:
    void initShaders()
    {
        // build and compile shaders
        // -------------------------

        static Shader text_shader = initFontRender();
        shaders["text"] = &text_shader;

        shaders["default_model"] = new Shader("./shaders/1.model_loading.vs", "./shaders/1.model_loading.fs");

        shaders["base2d2"] = new Shader("./shaders/base2d2.vs", "./shaders/base2d2.fs");

        shaders["beergui"] = new Shader("./shaders/beergui.vs", "./shaders/beergui.fs");

        // static Shader base_2d_shader = initBase2DRender();
        // rootContext->shaders["base_2d_shader"] = &base_2d_shader;
    }

    void initTextures();

};

void RenderContext::initTextures(){
    new BeerTexture;
}

#endif

