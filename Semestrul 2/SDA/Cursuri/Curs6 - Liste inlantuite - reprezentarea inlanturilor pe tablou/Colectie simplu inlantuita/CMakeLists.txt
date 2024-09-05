cmake_minimum_required(VERSION 3.27)
project(Implementare___Colectie___Reprezentare_simplu_inlantuita_cu_inlantuiri_pe_tablou_static)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Implementare___Colectie___Reprezentare_simplu_inlantuita_cu_inlantuiri_pe_tablou_static
        App.cpp
        Colectie.cpp
        Colectie.h
        Iterator.cpp
        Iterator.h)
