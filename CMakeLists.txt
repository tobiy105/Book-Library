cmake_minimum_required(VERSION 2.8)

project(comp1921 C)

#change this to Release to activate optimization and compile without debug symbols
set(CMAKE_BUILD_TYPE Debug)

include_directories(unity/include)

#adds arbitrary flags to the compiler.
#this one is used to generate the files we give in input to Egypt.
set(CMAKE_C_FLAGS "-std=c99 -fdump-rtl-expand")

#creates an executable by compiling and linking a list of space separated C files.
add_executable(library main.c book_management.c user_management.c)

#executable for the creation of unit test.
add_executable(unit_tests unit_tests-1.c Unity/src/unity.c user_management.c book_management.c)


