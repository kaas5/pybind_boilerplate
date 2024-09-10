#pragma once
#define GLFW_INCLUDE_NONE // volgorde includes glfw en glad maakt hierdoor niet uit
#include <pybind11/pybind11.h>
#include <vector>
#include <iostream>
#include "glad/gl.h"
#include "glfw3.h"

#include "mijnlib.h"

namespace py = pybind11;

class Render{
    static Render* currentInstance;
    //py::list& points;
    std::vector<Vector2> points;
    public:
        Render();
        /*static void drawCallback();
        void setupDrawCallback();
        //int Draw2(const py::list& list);
        void Display();
        
        int Draw();*/
        void SetDrawList(const py::list& vector2List);
};