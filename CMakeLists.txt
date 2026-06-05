cmake_minimum_required(VERSION 3.20)

project(adventofcode)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES
        "*.cpp"
)

add_executable(adventofcode
        main.cpp
)

target_include_directories(adventofcode PRIVATE
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/adventofcode*
)