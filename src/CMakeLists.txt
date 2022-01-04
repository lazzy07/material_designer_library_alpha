cmake_minimum_required(VERSION 3.15)

set(CMAKE_GENERATOR_PLATFORM x64)
project(matd_library)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DMATD_DEBUG")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__CL_ENABLE_EXCEPTIONS")

file(GLOB LIBRARY_CORE_SOURCE_FILES 
"core/*.cpp" "core/*.hpp"
)
source_group("core" FILES ${LIBRARY_CORE_SOURCE_FILES})

file(GLOB LIBRARY_ENGINE_MATD_SOURCE_FILES 
"engine/matd/*.cpp" "engine/matd/*.hpp"
)
source_group("engine\\matd" FILES ${LIBRARY_ENGINE_MATD_SOURCE_FILES})

file(GLOB LIBRARY_ENGINE_OPENCL_SOURCE_FILES 
"engine/vendor/opencl/*.cpp" "engine/vendor/opencl/*.hpp"
)
source_group("engine\\vendor\\opencl" FILES ${LIBRARY_ENGINE_OPENCL_SOURCE_FILES})

file(GLOB LIBRARY_ENGINE_CUDA_SOURCE_FILES 
"engine/vendor/cuda/*.cpp" "engine//vendor/cuda/*.hpp"
)
source_group("engine\\vendor\\cuda" FILES ${LIBRARY_ENGINE_CUDA_SOURCE_FILES})

file(GLOB LIBRARY_DATA_TYPES_MATD_SOURCE_FILES 
"types/matd/*.cpp" "types/matd/*.hpp"
)
source_group("types\\matd" FILES ${LIBRARY_DATA_TYPES_MATD_SOURCE_FILES})

file(GLOB LIBRARY_DATA_TYPES_OPENCL_SOURCE_FILES 
"types/vendor/opencl/*.cpp" "types/vendor/opencl/*.hpp"
)
source_group("types\\vendor\\opencl" FILES ${LIBRARY_DATA_TYPES_OPENCL_SOURCE_FILES})

file(GLOB LIBRARY_DATA_TYPES_CUDA_SOURCE_FILES 
"types/vendor/cuda/*.cpp" "types/vendor/cuda/*.hpp"
)
source_group("types\\vendor\\cuda" FILES ${LIBRARY_DATA_TYPES_CUDA_SOURCE_FILES})

file(GLOB LIBRARY_DATA_FUNCTIONS_SOURCE_FILES 
"functions/data_graph/*.cpp" "functions/data_graph/*.hpp"
)
source_group("functions\\data" FILES ${LIBRARY_DATA_FUNCTIONS_SOURCE_FILES})

file(GLOB LIBRARY_SHADER_FUNCTIONS_SOURCE_FILES 
"functions/shader_graph/*.cpp" "functions/shader_graph/*.hpp"
)
source_group("functions\\shader" FILES ${LIBRARY_SHADER_FUNCTIONS_SOURCE_FILES})

file(GLOB LIBRARY_CORE_FUNCTIONS_SOURCE_FILES 
"functions/core/*.cpp" "functions/core/*.hpp"
)
source_group("functions\\core" FILES ${LIBRARY_CORE_FUNCTIONS_SOURCE_FILES})


file(GLOB LIBRARY_GRAPHS_CORE_SOURCE_FILES 
"graphs/core/*.cpp" "graphs/core/*.hpp"
)
source_group("graphs\\core" FILES ${LIBRARY_GRAPHS_CORE_SOURCE_FILES})

file(GLOB LIBRARY_GRAPHS_DATA_SOURCE_FILES 
"graphs/data_graph/*.cpp" "graphs/data_graph/*.hpp"
)
source_group("graphs\\data" FILES ${LIBRARY_GRAPHS_DATA_SOURCE_FILES})

file(GLOB LIBRARY_GRAPHS_KERNEL_SOURCE_FILES 
"graphs/kernel_graph/*.cpp" "graphs/kernel_graph/*.hpp"
)
source_group("graphs\\kernel" FILES ${LIBRARY_GRAPHS_KERNEL_SOURCE_FILES})


file(GLOB LIBRARY_GRAPHS_SHADER_SOURCE_FILES 
"graphs/shader_graph/*.cpp" "graphs/shader_graph/*.hpp"
)
source_group("graphs\\shader" FILES ${LIBRARY_GRAPHS_SHADER_SOURCE_FILES})

add_library(${PROJECT_NAME} 
  ${LIBRARY_CORE_SOURCE_FILES} 
  ${LIBRARY_ENGINE_MATD_SOURCE_FILES} 
  ${LIBRARY_ENGINE_OPENCL_SOURCE_FILES} 
  ${LIBRARY_ENGINE_CUDA_SOURCE_FILES} 
  ${LIBRARY_DATA_FUNCTIONS_SOURCE_FILES} 
  ${LIBRARY_SHADER_FUNCTIONS_SOURCE_FILES}
  ${LIBRARY_CORE_FUNCTIONS_SOURCE_FILES}
  ${LIBRARY_GRAPHS_CORE_SOURCE_FILES}
  ${LIBRARY_GRAPHS_DATA_SOURCE_FILES}
  ${LIBRARY_GRAPHS_KERNEL_SOURCE_FILES}
  ${LIBRARY_GRAPHS_SHADER_SOURCE_FILES}
  ${LIBRARY_DATA_TYPES_MATD_SOURCE_FILES}
  ${LIBRARY_DATA_TYPES_OPENCL_SOURCE_FILES}
  ${LIBRARY_DATA_TYPES_CUDA_SOURCE_FILES}
)

target_include_directories(${PROJECT_NAME} 
  PRIVATE ../vendor/opencl/include
  PUBLIC ../vendor/json/include
  PUBLIC ../vendor/spdlog-1.8.5/include
)

target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/../vendor/opencl/lib/x86_64/OpenCL.lib )

set_target_properties( ${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${DIST_DIR} )