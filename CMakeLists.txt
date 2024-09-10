cmake_minimum_required(VERSION 3.4...3.18)

SET(MODULE_NAME "mijnlib")

project(${MODULE_NAME})

add_subdirectory(pybind11)
add_library(delib src/mijnlib.cpp)

pybind11_add_module(${MODULE_NAME} pybind_wrapper.cpp)

target_link_libraries(${MODULE_NAME} PUBLIC delib)
target_include_directories(${MODULE_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)