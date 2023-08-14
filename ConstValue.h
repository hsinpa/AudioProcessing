//
// Created by HsinPa on 8/14/2023.
//

#ifndef AUDIOSIGNALPROCESS_CONSTVALUE_H
#define AUDIOSIGNALPROCESS_CONSTVALUE_H

#include "vector"

struct DSPOutput {
private:
    int _length;
public:
    std::vector<float> ImX;
    std::vector<float> ReX;

    DSPOutput(int lens):
    _length(lens),
    ImX(std::vector<float>(lens)),
    ReX(std::vector<float>(lens))
    {

    }

    int Length() {
        return _length;
    }
};

extern const int BUFFER_SIZE = 8192;

#endif //AUDIOSIGNALPROCESS_CONSTVALUE_H
