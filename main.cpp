#define MINIAUDIO_IMPLEMENTATION

#include <iostream>
#include "DFT.h"
#include "./library/miniaudio.h"

int main() {
    //Hsinpa::DFT dft = Hsinpa::DFT();

    const char* sample_mp3_path = "../assets/file_example_MP3_1MG.mp3";
    ma_result result;
    ma_engine engine;
    ma_sound sound;

    result = ma_sound_init_from_file(&engine, sample_mp3_path, 0, NULL, NULL, &sound);

    if (result != MA_SUCCESS) {
        return result;  // Failed to initialize the engine.
    }

    ma_sound_start(&sound);

    printf("Press Enter to quit...");
    getchar();

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
