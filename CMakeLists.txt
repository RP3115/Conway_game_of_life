cmake_minimum_required(VERSION 3.1)
project(GameOfLife VERSION 0.1.0 LANGUAGES CXX)
add_executable(GameOfLife main.cpp Cell.cpp Grid.cpp Simulation.cpp Workflow.cpp)