cmake_minimum_required(VERSION 3.20)
project(task1)

set(CMAKE_CXX_STANDARD 20)
set(SRCS
    "main.cpp"
    "symmetric_matrix.cpp"
    "random_generator.cpp" quadratic_matrix.cpp quadratic_matrix.h lu_helper.cpp lu_helper.h vector.cpp vector.h)

add_executable(task1 ${SRCS})
