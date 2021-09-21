cmake_minimum_required(VERSION 3.8)
project(cs350_geometry_test)

############################
# Testing
add_executable(${PROJECT_NAME} common.hpp geometry.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC cs350_engine) 

# GTest
find_package(GTest CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC GTest::gtest GTest::gtest_main)
enable_testing()
add_test(NAME ${PROJECT_NAME}  COMMAND ${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

