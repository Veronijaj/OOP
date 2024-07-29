cmake_minimum_required(VERSION 3.4)
project(oopprog1)
set(CMAKE_CXX_STANDARD 20)

add_library(prog1 func.h func.cpp)
link_libraries(prog1)
add_executable(main lab1main.cpp)
add_compile_options(--coverage)
add_link_options(--coverage)