cmake_minimum_required(VERSION 3.10)  
project(y-2 C)  

add_library(arraylist arraylist.c arraylist.h)
add_library(recipe recipe.c recipe.h)
add_library(ui ui.c ui.h)

add_executable(y-2 main.c)  
target_link_libraries(y-2 arraylist recipe ui)