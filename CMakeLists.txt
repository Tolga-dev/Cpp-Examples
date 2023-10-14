
cmake_minimum_required(VERSION 3.23)
project(CppExamplePractices)


set(CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_FLAGS -pthread)
#set(CMAKE_CXX_COMPILER "clang")

#Adding Test
option(ENABLE_TESTS " Enable The Tests " ON)
if(ENABLE_TESTS)
    find_package(Catch2 3 REQUIRED)
    message("Enabled Test Catch2")
endif(ENABLE_TESTS)
unset(ENABLE_TESTS CACHE)

#Adding Specific Flags
option(ENABLE_SPECIFIC_FLAG "Enable The Flag" OFF)
if(ENABLE_SPECIFIC_FLAG)
    set (CMAKE_CXX_FLAGS -lpcap -pthread)
    target_link_libraries(CppExamplePractices ${PCAP_LIBRARY})
endif(ENABLE_SPECIFIC_FLAG)
unset(ENABLE_TESTS CACHE)

set(SFML_DIR /home/xamblot/CLionProjects/textEditor/External)
include_directories(${SFML_DIR})

find_package(SFML 2 REQUIRED COMPONENTS system window graphics network audio)
if(SFML_FOUND)
    message("yeap")
endif()


#add_executable(CppExamplePractices Casts/Static_Cast.cpp)
#add_executable(CppExamplePractices Concepts/Concepts.cpp)
#add_executable(CppExamplePractices AtCoder/main.cpp)
#add_executable(CppExamplePractices MemoryBarriers/LockFreeProgramming.cpp)
#add_executable(CppExamplePractices CompetitiveProgram/Dynamic/practice.cpp)
#add_executable(CppExamplePractices CodeWars/Pantabonacci.cpp)
add_executable(CppExamplePractices Class/main.cpp)

target_link_libraries(CppExamplePractices PRIVATE Catch2::Catch2WithMain PRIVATE Catch2::Catch2 sfml-audio sfml-network sfml-graphics sfml-window sfml-system)


