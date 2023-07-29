#ifndef RENDER_BLOCKS_H
#define RENDER_BLOCKS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>
#include <beercraft/context/render_context.h>
#include <beercraft/context/game_context.h>

#include <bits/stdc++.h>
using namespace std;

class BlockRenderer{
    public:
    BlockRenderer(RenderContext* renderContext_, GameContext* gameContext_):renderContext(renderContext_){
        gameContext = gameContext_;
    }

    void render(){
        renderBlocks();
    }

    private:
    RenderContext* renderContext;
    GameContext *gameContext;
        glm::vec3 blockScale = glm::vec3(0.5f, 0.5f, 0.5f);
    // default: glm::vec3 blockScale(0.2f, 0.2f, 0.2f);

    void renderBlocks()
    {
        renderContext->shaders["default_model"]->use();

        glm::mat4 unitMat = glm::mat4(1.0f);

        for (int i = 0; i <= 3; i++)
        {
            glm::mat4 model = unitMat;
            if (i == 0)
            {
                model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
                // model = glm::scale(model, blockScale);                      // it's a bit too big for our scene, so scale it down
                // model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
                renderContext->shaders["default_model"]->setMat4("model", model);
                gameContext->getBlockByID(2)->getModel()->Draw(*renderContext->shaders["default_model"]);
            }

            if (i == 1)
            {
                model = glm::translate(model, glm::vec3(3.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
                // model = glm::scale(model, blockScale);                      // it's a bit too big for our scene, so scale it down
                // model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
                renderContext->shaders["default_model"]->setMat4("model", model);
                gameContext->getBlockByID(1)->getModel()->Draw(*renderContext->shaders["default_model"]);
            }
            if (i == 2)
            {
                model = glm::translate(model, glm::vec3(6.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
                // model = glm::scale(model, blockScale);                      // it's a bit too big for our scene, so scale it down
                // model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
                renderContext->shaders["default_model"]->setMat4("model", model);
                gameContext->getBlockByID(58)->getModel()->Draw(*renderContext->shaders["default_model"]);
            }
            if (i == 3)
            {
                model = glm::translate(model, glm::vec3(9.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
                // model = glm::scale(model, blockScale);                      // it's a bit too big for our scene, so scale it down
                // model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
                renderContext->shaders["default_model"]->setMat4("model", model);
                gameContext->getBlockByID(61)->getModel()->Draw(*renderContext->shaders["default_model"]);
            }

            // Model ourModel("objects/door/Wooden-Door.obj");
            // ourModel.Draw(*renderContext->shaders["default_model"]);
        }
    }
    // void renderBlocks_AxisTest()
    // {
    //     renderContext->shaders["default_model"]->use();

    //     glm::mat4 unitMat = glm::mat4(1.0f);

    //     for (int i = 0; i <= 1; i++)
    //     {
    //         glm::mat4 model = unitMat;
    //         if (i == 0)
    //         {
    //             model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
    //             model = glm::scale(model, blockScale);                      // it's a bit too big for our scene, so scale it down
    //             renderContext->shaders["default_model"]->setMat4("model", model);
    //             gameContext->getBlockByID(2)->getModel()->Draw(*renderContext->shaders["default_model"]);
    //         }
    //         if (i == 1)
    //         {
    //             model = glm::translate(model, glm::vec3(0.5f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
    //             model = glm::scale(model, blockScale);                      // it's a bit too big for our scene, so scale it down
    //             renderContext->shaders["default_model"]->setMat4("model", model);
    //             gameContext->getBlockByID(1111)->getModel()->Draw(*renderContext->shaders["default_model"]);
    //         }
    //     }
    // }
};

#endif