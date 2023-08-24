cmake_minimum_required(VERSION 3.25)
project(AudioSignalProcess LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

add_library(AudioSignalProcessLib SHARED library.cpp
        DFT.h
        DFT.cpp
        ConstValue.h
        FFT.cpp
        FFT.h)

add_library(AudioSignalDevLib SHARED
        plugin/glfw/glfw3.h
        plugin/glfw/glfw3native.h
        library/miniaudio.h)
set_target_properties(AudioSignalDevLib PROPERTIES LINKER_LANGUAGE CXX)


set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/plugin/imgui)
add_library(IMGUI STATIC)
target_sources( IMGUI
        PRIVATE
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui.cpp

        PRIVATE
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)
target_include_directories( IMGUI
        PUBLIC ${IMGUI_DIR}
        PUBLIC ${IMGUI_DIR}/backends
)

link_directories(plugin/glfw)
add_executable(AudioSignalProcess main.cpp utility/AudioUtility.cpp utility/AudioUtility.h)
target_link_libraries(AudioSignalProcess AudioSignalProcessLib glfw3 IMGUI)
