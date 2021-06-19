cmake_minimum_required(VERSION 3.15)

set(CMAKE_GENERATOR_PLATFORM x64)
project(matd_library)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DMATD_DEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D__CL_ENABLE_EXCEPTIONS")

file(GLOB LIBRARY_CORE_SOURCE_FILES 
"core/*.cpp" "core/*.hpp"
)
source_group("core" FILES ${LIBRARY_CORE_SOURCE_FILES})

file(GLOB_RECURSE LIBRARY_ENGINE_SOURCE_FILES 
"engine/*.cpp" "engine/*.hpp"
)
source_group("engine" FILES ${LIBRARY_ENGINE_SOURCE_FILES})

file(GLOB_RECURSE LIBRARY_DATA_TYPES_SOURCE_FILES 
"types/*.cpp" "types/*.hpp"
)
source_group("types" FILES ${LIBRARY_DATA_TYPES_SOURCE_FILES})

file(GLOB LIBRARY_FUNCTIONS_SOURCE_FILES 
"functions/*.cpp" "functions/*.hpp"
)
source_group("functions" FILES ${LIBRARY_FUNCTIONS_SOURCE_FILES})

file(GLOB LIBRARY_GRAPHS_SOURCE_FILES 
"graphs/*.cpp" "graphs/*.hpp"
)
source_group("graphs" FILES ${LIBRARY_GRAPHS_SOURCE_FILES})


add_library(${PROJECT_NAME} 
  ${LIBRARY_CORE_SOURCE_FILES} 
  ${LIBRARY_ENGINE_SOURCE_FILES} 
  ${LIBRARY_FUNCTIONS_SOURCE_FILES} 
  ${LIBRARY_GRAPHS_SOURCE_FILES}
  ${LIBRARY_DATA_TYPES_SOURCE_FILES}
)

target_include_directories(${PROJECT_NAME} 
  PRIVATE ../vendor/opencl/include
  PUBLIC ../vendor/spdlog-1.8.5/include
)

target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/../vendor/opencl/lib/x86_64/OpenCL.lib )

set_target_properties( ${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${DIST_DIR} )