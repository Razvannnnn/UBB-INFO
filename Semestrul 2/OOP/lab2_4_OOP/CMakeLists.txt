cmake_minimum_required(VERSION 3.22.1)
project(lab2_4_OOP C)

set(CMAKE_C_STANDARD 11)

add_executable(lab2_4_OOP main.c
        domeniu.h
        domeniu.c
        teste.h
        teste.c
        repository.h
        repository.c
        validare.h
        validare.c
        service.h
        service.c
        ui.h
        ui.c
        MyList.h
        MyList.c)
