cmake_minimum_required(VERSION 3.16)
project(physics_sim CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(physics_sim
        src/PhysicsSim.cpp
        tests/test_main.cpp
)
