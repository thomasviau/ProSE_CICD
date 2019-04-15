cmake_minimum_required(VERSION 3.9)
set(CMAKE_C_STANDARD 99)

project(CICD C)
project(CICDTest C)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

include(CodeCoverage)
SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
SETUP_TARGET_FOR_COVERAGE(CICD_coverage CICDTest coverage)

file(GLOB_RECURSE everyFile "src/*.c" "src/*.h")
file(GLOB_RECURSE testFiles "test/*.c" "test/*.h")

add_executable(CICD ${everyFile})
add_executable(CICDTest ${testFiles})

find_library(cmocka NAMES libcmocka.so PATHS "/test/cmocka")
target_link_libraries(CICDTest cmocka)

target_include_directories(CICDTest PRIVATE ${PROJECT_SOURCE_DIR}/src ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${CMOCKA_PUBLIC_INCLUDE_DIRS})