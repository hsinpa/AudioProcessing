//
// Created by hsinp on 8/22/2023.
//

#ifndef AUDIOSIGNALPROCESS_AUDIOUTILITY_H
#define AUDIOSIGNALPROCESS_AUDIOUTILITY_H
#include <cmath>


class AudioUtility {

public:
    static void create_sine_wave(float amplitude, float phase, int frequency, float* output) {
        int output_size = sizeof(output);

        for (int i = 0; i < output_size; i++) {
            auto theta = 2 * M_PI * frequency * i;

            output[i] = static_cast<float>(std::cos(theta + phase) * amplitude);
        }
    }
};

#endif //AUDIOSIGNALPROCESS_AUDIOUTILITY_H
