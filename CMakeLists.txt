cmake_minimum_required(VERSION 3.9)
set(CMAKE_C_STANDARD 99)

# Project name
set(PROSE_PROJECT_NAME NexetupC)

# Define projects
project(${PROSE_PROJECT_NAME} C)
project(${PROSE_PROJECT_NAME}Test C)

# Module path (usefull for finding libs)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

# Coverage
include(CodeCoverage)
SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
SETUP_TARGET_FOR_COVERAGE(coverage ${PROSE_PROJECT_NAME}Test coverage)

# Include every src files
file(GLOB_RECURSE everyFile "src/*.c" "src/*.h")
add_executable(${PROSE_PROJECT_NAME} ${everyFile})

# Include every test files
file(GLOB_RECURSE testFiles "test/*.c" "test/*.h")
add_executable(${PROSE_PROJECT_NAME}Test ${testFiles})

# CMocka lib
SET(CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/test/cmocka")
find_library(LIB_CMOCKA libCMocka NAMES CICD.so)

if (NOT LIB_CMOCKA)
    message(FATAL_ERROR "library not found")
endif()

target_link_libraries(${PROSE_PROJECT_NAME}Test ${LIB_CMOCKA})

# Final includes
target_include_directories(${PROSE_PROJECT_NAME}Test PRIVATE ${PROJECT_SOURCE_DIR}/src ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${CMOCKA_PUBLIC_INCLUDE_DIRS})