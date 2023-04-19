cmake_minimum_required(VERSION 3.10)
project(Projekt3)

add_subdirectory(matplotplusplus)

set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}/${PROJECT_SOURCE_DIR}")

find_package (Eigen3 3.4 REQUIRED NO_MODULE)

add_executable(plot main.cpp)
target_link_libraries(plot matplot)
target_link_libraries(plot Eigen3::Eigen)