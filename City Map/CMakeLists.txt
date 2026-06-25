cmake_minimum_required(VERSION 3.30)
project(City_Map)

set(CMAKE_CXX_STANDARD 26)

add_executable(City_Map main.cpp
        Map.cpp
        Map.h)
