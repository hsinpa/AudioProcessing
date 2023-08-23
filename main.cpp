#define MINIAUDIO_IMPLEMENTATION

#include <iostream>
#include "DFT.h"
#include "./library/miniaudio.h"
#include "./utility/AudioUtility.h"

void test_generate_sine_wave() {
    int sample_size= 2048;
    float output[sample_size];
    AudioUtility::create_sine_wave(10, 0, 200, output);

    for (int i = 0; i < sample_size; i += 100) {
        std::cout << "Sine " << output[i] << std::endl;
    }
}

int main() {

    test_generate_sine_wave();
    return 0;
}

