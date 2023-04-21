cmake_minimum_required(VERSION 3.15)
project(Projekt3)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(matplotplusplus)
add_subdirectory(SDL)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")

find_package(Eigen3 3.4 REQUIRED NO_MODULE)

add_executable(plot main.cpp)
target_link_libraries(plot matplot)
target_link_libraries(plot Eigen3::Eigen)

# https://wiki.libsdl.org/SDL2/README/cmake
set(VIZ_SOURCES viz.cpp)
add_executable(viz ${VIZ_SOURCES})
if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(viz SDL2::SDL2main)
endif()
target_link_libraries(viz SDL2::SDL2)
