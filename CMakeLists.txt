cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(untitled main.cpp
        Task.h
        Task.cpp
        ToDoList.h
        ToDoList.cpp
        HighPriorityTask.h
        HighPriorityTask.cpp
        Operations.h
        Operations.cpp
        Input.h
        Input.cpp)
