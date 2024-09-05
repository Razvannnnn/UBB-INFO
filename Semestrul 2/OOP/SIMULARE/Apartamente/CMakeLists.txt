cmake_minimum_required(VERSION 3.28)
project(Apartamente)

set(CMAKE_PREFIX_PATH "C:\\Qt\\6.7.0\\mingw_64")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
include_directories(.)

add_executable(Apartamente main.cpp
        domain.cpp
        domain.h
        service.cpp
        service.h
        repo.cpp
        repo.h
        gui.cpp
        gui.h
)

target_link_libraries(Apartamente Qt6::Widgets)
