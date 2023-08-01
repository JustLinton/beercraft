#ifndef LOGGER_H
#define LOGGER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>
#include <beercraft/context/root_context.h>

#include <bits/stdc++.h>
using namespace std;

class Logger
{
private:
    /* data */
public:
    void error(string s)
    {
        printf("\033[0m\033[1;31m[ERROR] %s\033[0m\n", s.c_str());
    }

    void info(string s){
        printf("\033[0m\033[1;34m[INFO] %s\033[0m\n", s.c_str());
    }
};

static Logger logger;

#endif

