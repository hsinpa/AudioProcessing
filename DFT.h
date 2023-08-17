//
// Created by HsinPa on 8/14/2023.
//

#ifndef AUDIOSIGNALPROCESS_DFT_H
#define AUDIOSIGNALPROCESS_DFT_H

#include "ConstValue.h"

namespace Hsinpa {
    class DFT {

    private:
        int _head;
        float buffer_array[BUFFER_SIZE] {0};

    public:
        DFT();

        void Forward(const float data[]);

    };
} // Hsinpa

#endif //AUDIOSIGNALPROCESS_DFT_H
