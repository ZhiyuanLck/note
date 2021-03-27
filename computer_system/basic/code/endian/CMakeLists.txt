cmake_minimum_required(VERSION 3.15)

project(endian)

add_compile_options(-g -Wall -O2 -std=c++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)

include_directories(${PROJECT_SOURCE_DIR}/../include)
add_executable(${PROJECT_NAME}.out endian.cpp)

add_custom_target(run
    COMMAND ${PROJECT_NAME}.out
    DEPENDS ${PROJECT_NAME}.out
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)
