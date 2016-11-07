cmake_minimum_required(VERSION 2.8)

project(SCTtools)

set(DEBUG_FLAGS "-std=c++11 -g -O1 -Wall")
set(RELEASE_FLAGS "-std=c++11 -O3 -Wall")

set(CMAKE_CXX_FLAGS ${RELEASE_FLAGS})
set(CMAKE_CXX_FLAGS_DEBUG ${DEBUG_FLAGS})
set(CMAKE_CONFIGURATION_TYPES Debug Release)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})
set(SOURCES src/main src/Graph.cc)

enable_testing()

include_directories(src header)

add_executable (SCTtools ${SOURCES})

#add_subdirectory(src header)