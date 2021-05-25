cmake_minimum_required(VERSION 3.17)
project(SupportMapping)

set(CMAKE_CXX_STANDARD 11)

add_executable(SupportMapping main.cpp SupportMapping.h vec3.h Exception.h Shapes.h)

