cmake_minimum_required(VERSION 3.25)
project(AudioSignalProcess)

set(CMAKE_CXX_STANDARD 23)

add_library(AudioSignalProcessLib SHARED library.cpp
        DFT.h
        DFT.cpp
        ConstValue.h
        FFT.cpp
        FFT.h)

link_directories(${CMAKE_SOURCE_DIR}/library ${CMAKE_SOURCE_DIR}/utility)
add_executable(AudioSignalProcess main.cpp utility/AudioUtility.cpp utility/AudioUtility.h)
target_link_libraries(AudioSignalProcess AudioSignalProcessLib)
