cmake_minimum_required(VERSION 3.28)
project(Lista_Ordonata___cu_pozitie_iterator)

set(CMAKE_CXX_STANDARD 14)

include_directories("Proiect C++")
include_directories(Teste)

add_executable(Lista_Ordonata___cu_pozitie_iterator
        "Proiect C++/App.cpp"
        "Proiect C++/Iterator.cpp"
        "Proiect C++/Iterator.h"
        "Proiect C++/LO.cpp"
        "Proiect C++/LO.h"
        Teste/TestExtins.cpp
        Teste/TestExtins.h
        Teste/TestScurt.cpp
        Teste/TestScurt.h)
