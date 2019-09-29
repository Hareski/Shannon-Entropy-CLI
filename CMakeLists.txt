cmake_minimum_required(VERSION 3.0)
project(Information_theory C)

set(CMAKE_C_STANDARD 11)

add_executable(entropy main.c)
target_link_libraries(entropy m)
