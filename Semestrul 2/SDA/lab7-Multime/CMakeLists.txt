cmake_minimum_required(VERSION 3.22)
project(lab7_Multime)

set(CMAKE_CXX_STANDARD 14)

include_directories("Proiect C++/Multime")
include_directories(Teste)

add_executable(lab7_Multime
        "Proiect C++/Multime/App.cpp"
        "Proiect C++/Multime/IteratorMultime.cpp"
        "Proiect C++/Multime/IteratorMultime.h"
        "Proiect C++/Multime/Multime.cpp"
        "Proiect C++/Multime/Multime.h"
        Teste/TestExtins.cpp
        Teste/TestExtins.h
        Teste/TestScurt.cpp
        Teste/TestScurt.h)
