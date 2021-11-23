cmake_minimum_required(VERSION 3.20)
project(priorityQueues C)

set(CMAKE_C_STANDARD 99)

add_executable(priorityQueues main.c heap.c heap.h)
