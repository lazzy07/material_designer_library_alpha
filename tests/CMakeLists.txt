#This is the official Material Designer Library created by @lazzy07
cmake_minimum_required(VERSION 3.15)

set(This MatdTesting)

include_directories(This PRIVATE ../src PUBLIC ../include)

enable_testing()

add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/gtest-1.15.2 ${CMAKE_SOURCE_DIR}/build/googletest)

set(Sources
    MainTest.cpp
    VariablesTest.cpp
    BufferTest.cpp
    TextureTest.cpp
    VectorTest.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC 
    gtest_main
    matd_library
)

