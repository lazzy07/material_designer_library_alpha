cmake_minimum_required(VERSION 3.15)

set(CMAKE_GENERATOR_PLATFORM x64)

project(matd_v8_bindings)

# Essential include files to build a node addon,
# add this line in every CMake.js based project.
include_directories(${CMAKE_JS_INC})

##Matd library include files
include_directories(${PROJECT_NAME} PRIVATE ../src PUBLIC ../include)

# Declare the location of the source files
file(GLOB SOURCE_FILES "src/cpp/*.cpp" "src/cpp/*.hpp")

# This line will tell CMake that we're building a shared library
# from the above source files
# named after the project's name
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC})
# This line will give our library file a .node extension without any "lib" prefix
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

# Essential library files to link to a node addon,
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})

## Matd library
target_link_libraries(${PROJECT_NAME} matd_library)


# Include N-API wrappers for Node.js
execute_process(COMMAND node -p "require('node-addon-api').include"
WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
OUTPUT_VARIABLE NODE_ADDON_API_DIR
)

string(REPLACE "\n" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
string(REPLACE "\"" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${NODE_ADDON_API_DIR} PRIVATE ../include)
add_definitions(-DNAPI_VERSION=4)



set_target_properties( ${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_GENERATOR_PLATFORM} RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_GENERATOR_PLATFORM})
