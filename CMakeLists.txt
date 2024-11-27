# CMake Version
cmake_minimum_required(VERSION 3.10.0)

# Project
project(bagarrio VERSION 0.1.0 LANGUAGES C CXX)

# C++
set(CMAKE_CXX_STANDARD 17)

# SDL2
find_package(SDL2 REQUIRED)

# Include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${SDL2_INCLUDE_DIRS})


# Create executable 
add_executable(${PROJECT_NAME} src/main.cpp src/p2p/tcp_server.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

if(WIN32)
  target_link_libraries(${PROJECT_NAME} ws2_32 mswsock)
endif()