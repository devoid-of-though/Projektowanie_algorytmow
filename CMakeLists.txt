cmake_minimum_required(VERSION 3.28)
project(Projektowanie_algorytmów)

set(CMAKE_CXX_STANDARD 17)
include_directories(${CMAKE_SOURCE_DIR}/header\ files)

add_executable(Projektowanie_algorytmow "source files/main.cpp"
        "source files/check.cpp"
        "source files/introsort.cpp"
        "source files/heapsort.cpp"
        "source files/quicksort.cpp"
        "source files/fileMaker.cpp")
