cmake_minimum_required(VERSION 3.10)

project(KFS)
find_package(Eigen3 REQUIRED NO_MODULE)
set(SRC_CPP
    src/plotting/Display.cpp
    src/robot/Robot.cpp
    src/robot/Bicycle.cpp
    src/robot/Simulation.cpp
    src/utility.cpp
    src/kalmanFilters/KalmanFilterBase.cpp

)
add_executable(${PROJECT_NAME} main.cpp ${SRC_CPP})

target_link_libraries(${PROJECT_NAME} SDL2 Eigen3::Eigen)