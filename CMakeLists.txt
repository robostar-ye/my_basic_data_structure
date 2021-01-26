cmake_minimum_required(VERSION 3.10)
project(my_basic_data_structure)

set(CMAKE_CXX_STANDARD 11)

add_executable(test sources/test.cpp headers/Complex.hpp headers/String.hpp)