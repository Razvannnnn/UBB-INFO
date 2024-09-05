cmake_minimum_required(VERSION 3.28)
project(PracticMELODII2)

set(CMAKE_PREFIX_PATH "C:\\Qt\\6.7.0\\mingw_64")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_STANDARD 17)
include_directories(.)

add_executable(PracticMELODII2 main.cpp
        repo.cpp
        repo.h
        service.cpp
        service.h
        domain.cpp
        domain.h
        GUI.cpp
        GUI.h
        Model.h
        observer.cpp
        observer.h)

target_link_libraries(PracticMELODII2 Qt6::Widgets)