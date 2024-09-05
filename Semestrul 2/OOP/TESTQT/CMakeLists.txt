cmake_minimum_required(VERSION 3.28)
project(lab6)

set(CMAKE_PREFIX_PATH "C:\\Qt\\6.7.0\\mingw_64\\bin\\")
find_package(Qt6Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_STANDARD 17)
include_directories(.)
add_executable(TESTQT main.cpp)
target_link_libraries(TESTQT Qt6::Widgets)
