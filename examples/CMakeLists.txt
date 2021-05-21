cmake_minimum_required(VERSION 3.15)

set(CMAKE_GENERATOR_PLATFORM x64)
project(matd_examples)

file(GLOB TEST_SOURCE_FILES "getinfo/*.cpp" "getinfo/*.hpp")

add_executable(${PROJECT_NAME} ${TEST_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} matd_library)
target_include_directories(${PROJECT_NAME} PRIVATE ../src PUBLIC ../include)

set_target_properties( ${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/${CMAKE_GENERATOR_PLATFORM} )