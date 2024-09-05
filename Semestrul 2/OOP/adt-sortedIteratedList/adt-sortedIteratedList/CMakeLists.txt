cmake_minimum_required(VERSION 3.28)
project(adt_sortedIteratedList)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(adt_sortedIteratedList
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ListIterator.cpp
        ListIterator.h
        ShortTest.cpp
        ShortTest.h
        SortedIteratedList.cpp
        SortedIteratedList.h)
