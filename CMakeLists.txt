cmake_minimum_required(VERSION 3.10)

project(KFS)

set(SRC_CPP
    src/plotting/Display.cpp
    src/robot/Robot.cpp
    src/robot/Bicycle.cpp
    src/utility.cpp

)
add_executable(${PROJECT_NAME} main.cpp ${SRC_CPP})

target_link_libraries(${PROJECT_NAME} SDL2)