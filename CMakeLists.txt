#This is the official Material Designer Library created by @lazzy07
cmake_minimum_required(VERSION 3.15)

set(CMAKE_GENERATOR_PLATFORM x64)
set(DIST_DIR ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/${CMAKE_GENERATOR_PLATFORM})
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(MaterialDesigner)

add_subdirectory(src)
#v8 bindigs project
add_subdirectory(matd_v8)
#examples (used for testing as well)
add_subdirectory(examples)

add_definitions(/bigobj)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT matd_examples)
