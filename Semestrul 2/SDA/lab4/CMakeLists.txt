cmake_minimum_required(VERSION 3.27)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

include_directories("Lista Ordonata - cu pozitie iterator/Proiect C++")
include_directories("Lista Ordonata - cu pozitie iterator/Teste")

add_executable(lab4
        "Lista Ordonata - cu pozitie iterator/Proiect C++/App.cpp"
        "Lista Ordonata - cu pozitie iterator/Proiect C++/Iterator.cpp"
        "Lista Ordonata - cu pozitie iterator/Proiect C++/Iterator.h"
        "Lista Ordonata - cu pozitie iterator/Proiect C++/LO.cpp"
        "Lista Ordonata - cu pozitie iterator/Proiect C++/LO.h"
        "Lista Ordonata - cu pozitie iterator/Teste/TestExtins.cpp"
        "Lista Ordonata - cu pozitie iterator/Teste/TestExtins.h"
        "Lista Ordonata - cu pozitie iterator/Teste/TestScurt.cpp"
        "Lista Ordonata - cu pozitie iterator/Teste/TestScurt.h")
