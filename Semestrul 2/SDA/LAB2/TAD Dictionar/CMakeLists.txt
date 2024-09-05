cmake_minimum_required(VERSION 3.27)
project(TAD_Dictionar)

set(CMAKE_CXX_STANDARD 14)

include_directories(Proiect_C++)
include_directories(Teste)

add_executable(TAD_Dictionar
        Proiect_C++/App.cpp
        Proiect_C++/Dictionar.cpp
        Proiect_C++/Dictionar.h
        Proiect_C++/IteratorDictionar.cpp
        Proiect_C++/IteratorDictionar.h
        Teste/TestExtins.cpp
        Teste/TestExtins.h
        Teste/TestScurt.cpp
        Teste/TestScurt.h)
