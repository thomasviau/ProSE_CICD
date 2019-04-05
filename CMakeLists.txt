cmake_minimum_required(VERSION 3.9)
project(CICD C)

set(CMAKE_C_STANDARD 99)

file(GLOB_RECURSE everyFile "src/*.c" "src/*.h")
add_executable(CICD ${everyFile})

target_link_libraries(CICD pthread)