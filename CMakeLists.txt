cmake_minimum_required(VERSION 3.10)

project(KFS)

find_package(SDl)

add_executable(${PROJECT_NAME} main.cpp src/plotting/Display.cpp)

target_link_libraries(${PROJECT_NAME} SDL2)