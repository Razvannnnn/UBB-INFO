cmake_minimum_required(VERSION 3.27)
project(VectorDinamicCPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(VectorDinamicCPP)

add_executable(VectorDinamicCPP
        VectorDinamicCPP/main.cpp
        VectorDinamicCPP/Pet.cpp
        VectorDinamicCPP/Pet.h
        VectorDinamicCPP/VectDinNewDelete.cpp
        VectorDinamicCPP/VectDinNewDelete.h
        VectorDinamicCPP/VectDinSmartPointer.cpp
        VectorDinamicCPP/VectDinSmartPointer.h
        VectorDinamicCPP/VectorDinamicTemplate.h)
