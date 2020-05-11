cmake_minimum_required(VERSION 3.5)

project(Catching)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(include)

file(GLOB_RECURSE LIBS src/*/*.cpp)

add_library(libs ${LIBS})

add_executable(main src/main.cpp)
add_executable(mainTests tests/test.cpp)

target_link_libraries(main libs)
target_link_libraries(mainTests libs)

enable_testing()
add_test(NAME mainTests COMMAND mainTests)
