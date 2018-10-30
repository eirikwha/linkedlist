cmake_minimum_required(VERSION 3.12)
project(linkedlist C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(linkedlist
        linked_list.c
        linked_list.h
        list_test.c)
