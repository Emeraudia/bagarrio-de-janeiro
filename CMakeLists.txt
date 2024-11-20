# CMake Version
cmake_minimum_required(VERSION 3.10.0)

# Project
project(bagarrio VERSION 0.1.0 LANGUAGES C CXX)

# SDL2
find_package(SDL2 REQUIRED)

# Include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${SDL2_INCLUDE_DIRS})

# Create executable 
add_executable(${PROJECT_NAME} src/main.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})