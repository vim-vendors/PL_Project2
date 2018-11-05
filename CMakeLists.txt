cmake_minimum_required(VERSION 3.12)
project(PL_Project2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cmake-build-debug)

add_executable(PL_Project2
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Makefile
        cmake-build-debug/SetProject
        cmake-build-debug/SetProject.cbp
        CMakeLists.txt
        main.cpp)
