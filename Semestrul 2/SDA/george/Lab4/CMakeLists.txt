cmake_minimum_required(VERSION 3.28)
project(Lab4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab4
        App.cpp
        IteratorLP.cpp
        IteratorLP.h
        Lista.cpp
        Lista.h
        TestExtins.cpp
        TestExtins.h
        TestScurt.cpp
        TestScurt.h)
