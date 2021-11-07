cmake_minimum_required(VERSION 3.20)
project(task1)

set(CMAKE_CXX_STANDARD 20)

set(SRCS
        main.cpp
        symmetric_matrix.cpp
        random_generator.cpp
        quadratic_matrix.cpp
        lu_helper.cpp
        vector.cpp
        clock_guard.cpp
        ldlt_helper.cpp
        checker.cpp)

add_executable(task1 ${SRCS})
