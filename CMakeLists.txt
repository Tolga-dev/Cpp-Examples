cmake_minimum_required(VERSION 3.23)
project(CppExamplePractices)


set(CMAKE_CXX_STANDARD 23)

set (CMAKE_CXX_FLAGS -pthread)

add_executable(CppExamplePractices mutual.cpp)


