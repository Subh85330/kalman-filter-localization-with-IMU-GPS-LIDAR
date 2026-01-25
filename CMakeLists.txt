cmake_minimum_required(VERSION 3.10)
set(CMAK)
project(KFS LANGUAGES CXX)
find_package(Eigen3 REQUIRED NO_MODULE)
set(SRC_CPP
    src/plotting/Display.cpp
    src/plotting/Grid.cpp
    src/robot/Robot.cpp
    src/robot/Bicycle.cpp
    src/robot/Simulation.cpp
    src/robot/sensors/GPSSensor.cpp
    src/utility.cpp
    src/kalmanFilters/KalmanFilterBase.cpp
    src/kalmanFilters/LinearKalmanFilter.cpp
    src/kalmanFilters/ExtendedKF.cpp
    src/kalmanFilters/UnscentedKF.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${SRC_CPP})

target_link_libraries(${PROJECT_NAME} SDL2 Eigen3::Eigen SDL2 SDL2_ttf)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets/fonts/ $<TARGET_FILE_DIR:${PROJECT_NAME}>)
    