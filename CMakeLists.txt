cmake_minimum_required(VERSION 3.15)
project(Projekt3)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(matplotplusplus)
add_subdirectory(SDL)
add_subdirectory(SDL2_gfx)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")

find_package(Eigen3 3.4 REQUIRED NO_MODULE)

add_executable(plot main.cpp)
target_link_libraries(plot matplot)
target_link_libraries(plot Eigen3::Eigen)

set(PLANAR_QUADROTOR_SOURCES PlanarQuadrotor/simulate.cpp PlanarQuadrotor/planar_quadrotor.cpp PlanarQuadrotor/planar_quadrotor_visualizer.cpp PlanarQuadrotor/lqr.cpp)
add_executable(planar_quadrotor ${PLANAR_QUADROTOR_SOURCES})
if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(planar_quadrotor SDL2::SDL2main)
endif()
target_link_libraries(planar_quadrotor SDL2::SDL2)
target_link_libraries(planar_quadrotor SDL2_gfx)
target_link_libraries(planar_quadrotor Eigen3::Eigen)
target_link_libraries(planar_quadrotor matplot)
target_include_directories(planar_quadrotor PRIVATE ${PROJECT_SOURCE_DIR})