# Declare which version of CMake we're using here.
cmake_minimum_required(VERSION 3.16.0)

# Project name Portable Pix Map (PPM)
project(PPM)

# Set aside an executable target to add source files to.
add_executable(${PROJECT_NAME} "")

# This header search allows CMake (and CLion) to know that all of the header files in the include directory are
# part of the project which makes automated code insight features work as well.
file(GLOB HEADERS ./ "*.h")
target_sources(${PROJECT_NAME} PRIVATE ${HEADERS})

target_sources(${PROJECT_NAME} PRIVATE main.cpp image.cpp)
