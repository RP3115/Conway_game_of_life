cmake_minimum_required(VERSION 3.1)
project(GameOfLife VERSION 0.1.0 LANGUAGES CXX)

enable_testing() #to  discover tests in test explorer 

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>
add_executable(GameOfLife main.cpp Cell.cpp Grid.cpp Simulation.cpp Workflow.cpp)

add_executable(DynamicGridtest DynamicGridtest.cpp Cell.cpp Grid.cpp Simulation.cpp) 

target_link_libraries(DynamicGridtest PRIVATE gtest) # link google test to this executable

include(GoogleTest)
gtest_discover_tests(DynamicGridtest) # discovers tests by asking the compiled test executable to enumerate its tests

set (CMAKE_CXX_FLAGS "-O3")
