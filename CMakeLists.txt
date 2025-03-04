cmake_minimum_required(VERSION 3.28)
project(DataStructureDemo C)

set(CMAKE_C_STANDARD 11)

add_executable(DataStructureDemo main.c
        seq_list.h
        seq_list.c
        link_list.c
        link_list.h
        doubly_linked_list.c
        doubly_linked_list.h
        stack.c
        stack.h
        queue.c
        queue.h)
