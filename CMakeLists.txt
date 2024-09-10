cmake_minimum_required(VERSION 3.4...3.18)
SET(MODULE_NAME "mijnlib")
project(${MODULE_NAME})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/pybind11/include
    "C:/Program Files/Python310/include"
)

add_library(delib src/mijnlib.cpp src/render.cpp src/gl.c)

add_subdirectory(pybind11)
pybind11_add_module(${MODULE_NAME} pybind_wrapper.cpp)

target_link_directories(${MODULE_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_link_libraries(${MODULE_NAME} PRIVATE delib glfw3dll)

target_include_directories(${MODULE_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "C:/Program Files/Python310/include"
)