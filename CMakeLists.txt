cmake_minimum_required(VERSION 3.26)
project(Sys_Calculator C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Sys_Calculator main.c)
target_link_libraries(Sys_Calculator m)  # Agrega la opción -lm para enlazar la biblioteca matemática