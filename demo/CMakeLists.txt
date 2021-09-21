cmake_minimum_required(VERSION 3.8)
project(cs350_geometry_demo)

# Demos
add_executable(${PROJECT_NAME} demo_renderer.cpp imgui.hpp)
target_link_libraries(${PROJECT_NAME} PUBLIC cs350_engine)
target_link_libraries(${PROJECT_NAME} PUBLIC imgui)
