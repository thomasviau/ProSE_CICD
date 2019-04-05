cmake_minimum_required(VERSION 3.9)
project(CICD C)

set(CMAKE_C_STANDARD 99)

add_executable(CICD src/account.c src/account.h src/bank_database.h src/bank_database.c src/consumers.c)

target_link_libraries(CICD pthread)