cmake_minimum_required(VERSION 3.20)
project(task2)

set(CMAKE_CXX_STANDARD 20)

add_executable(task2 main.cpp matrix.cpp matrix.h vector.cpp vector.h norm_matrix.cpp norm_matrix.h gmres.h clock_guard.cpp gmres.cpp)
