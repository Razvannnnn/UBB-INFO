cmake_minimum_required(VERSION 3.27)
project(lab2_7 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab2_7 main.c
        repo.c
        repo.h
        service.c
        service.h
        cheltuieli.c
        cheltuieli.h
        ui.c
        ui.h
        valid.c
        valid.h
        lista.h
        lista.c
)
