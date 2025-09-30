cmake_minimum_required(VERSION 4.0)  
project(y-2 C)  

add_library(arraylist
    arraylist.c
    arraylist.h
)

add_executable(y-2 main.c)  

target_link_libraries(y-2 arraylist)