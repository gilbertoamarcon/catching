cmake_minimum_required(VERSION 3.16.3)

project(Catching)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(include)

file(GLOB_RECURSE LIBS src/*/*.cpp)

add_library(libs ${LIBS})

add_executable(main src/main.cpp)
add_executable(test tests/test.cpp)

find_package(Catch2 REQUIRED)

target_link_libraries(test Catch2::Catch2)
target_link_libraries(test libs)
target_link_libraries(main libs)
