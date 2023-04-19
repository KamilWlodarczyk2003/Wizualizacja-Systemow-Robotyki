cmake_minimum_required(VERSION 3.10)
project(Projekt3)

add_subdirectory(matplotplusplus)

add_executable(plot main.cpp)
target_link_libraries(plot PUBLIC matplot)