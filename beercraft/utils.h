#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <map>
#include <string>

#include <beercraft/context/root_context.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>

#include <bits/stdc++.h>
using namespace std;

// template <class T>
// string float2Str(const T input, stringstream* sst)
// {
//     string tmp;
//     sst->clear();
//     (*sst) << input;
//     (*sst) >> tmp;
//     return tmp;
// }

template <class T>
T str2T(const string input, stringstream *sst)
{
    T tmp;
    sst->clear();
    (*sst) << input;
    (*sst) >> tmp;
    return tmp;
}

#endif