cmake_minimum_required(VERSION 3.20)
project(ABC C)

set(CMAKE_C_STANDARD 99)

SET(SOURCE_FILES
        main.c
        container.c
        container.h
        number.c
        number.h
        complex_number.h complex_number.c fraction_number.h fraction_number.c polar_number.h polar_number.c)

add_executable(ABC ${SOURCE_FILES})
