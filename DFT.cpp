//
// Created by HsinPa on 8/14/2023.
//
#include <cmath>
#include <iostream>
#include "DFT.h"
#include "ConstValue.h"
using namespace Hsinpa;

DFT::DFT() :_head(0) {
    std::cout << "DFT Created" << std::endl;
}

void DFT::Forward(const float *data) {
    int N = sizeof(data);
    int K = N / 2 + 1;

    std::vector<Complex> output(K);

    for (int k = 0; k < K; k++) {
        for (int n = 0; n < N; n++) {
            const float phi = static_cast<float>(M_PI * 2 * k * n) / static_cast<float>(N);
            float re = data[n] * std::cos(phi);
            float im = -data[n] * std::sin(phi);

            output[k].re += re;
            output[k].im += im;
        }
    }
}