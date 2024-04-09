cmake_minimum_required(VERSION 3.27)
project(Advanced_Bank_Management_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Advanced_Bank_Management_System
        main.cpp
        Manager.cpp
        Manager.h
        User.cpp
        User.h
        Transaction.cpp
        Transaction.h)