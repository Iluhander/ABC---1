cmake_minimum_required(VERSION 3.20)
project(ABC_OO)

set(CMAKE_CXX_STANDARD 14)

add_executable(ABC_OO main.cpp container.h number.h complex_number.h polar_number.h fraction_number.h fraction_number.cpp randGenerator.h polar_number.cpp complex_number.cpp container.cpp number.cpp)
