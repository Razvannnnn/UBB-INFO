cmake_minimum_required(VERSION 3.28)
project(Colectie2)

set(CMAKE_CXX_STANDARD 14)

include_directories("Proiect C++/Colectie")
include_directories(Teste)

add_executable(Colectie2
        "Proiect C++/Colectie/App.cpp"
        "Proiect C++/Colectie/Colectie.cpp"
        "Proiect C++/Colectie/Colectie.h"
        "Proiect C++/Colectie/IteratorColectie.cpp"
        "Proiect C++/Colectie/IteratorColectie.h"
        Teste/TestExtins.cpp
        Teste/TestExtins.h
        Teste/TestScurt.cpp
        Teste/TestScurt.h)
