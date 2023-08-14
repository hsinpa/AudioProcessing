cmake_minimum_required(VERSION 3.25)
project(AudioSignalProcess)

set(CMAKE_CXX_STANDARD 23)

add_library(AudioSignalProcessLib SHARED library.cpp
        DFT.h
        DFT.cpp
        ConstValue.h
        FFT.cpp
        FFT.h)

add_executable(AudioSignalProcess main.cpp)
target_link_libraries(AudioSignalProcess AudioSignalProcessLib)
