cmake_minimum_required(VERSION 3.27)
project(lab6)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_STANDARD 17)
include_directories(.)
add_executable(lab6 main.cpp
        vector.cpp
        vector.h
        produs.cpp
        produs.h
        repo.cpp
        repo.h
        service.cpp
        service.h
        ui.cpp
        ui.h
        validare.cpp
        validare.h)

add_executable(test
            vector.h
            vector.cpp
            test_vector.cpp
            )
