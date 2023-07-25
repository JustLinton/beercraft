#ifndef BLOCK_H
#define BLOCK_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>
#include <beercraft/context/render_context.h>
#include <graphics/model.h>

#include <bits/stdc++.h>
using namespace std;

class Block{
public:
    Block(unsigned int id_, string label_, string modelPath_){
        modelPath = modelPath_;
        label_ = label;
        id = id_;
        model = new Model(modelPath);
    }

    Model* getModel(){
        return model;
    }

private:
    string modelPath;
    Model* model;
    string label;
    unsigned int id;
};

#endif