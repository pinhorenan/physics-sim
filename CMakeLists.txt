cmake_minimum_required(VERSION 3.16)
project(physics_sim)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(physics_sim
        src/Vector2D.cpp
        src/RigidBody.cpp
        src/PhysicsSim.cpp
        tests/test_main.cpp
)
