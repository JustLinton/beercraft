#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <map>
#include <string>

#include <core/root_context.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>

#include <bits/stdc++.h>
using namespace std;

string float2Str(const float* input){
    string tmp;
    stringstream sst;
    sst << *input;
    sst >> tmp;
    return tmp;
}

#endif