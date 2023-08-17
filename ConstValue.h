//
// Created by HsinPa on 8/14/2023.
//

#ifndef AUDIOSIGNALPROCESS_CONSTVALUE_H
#define AUDIOSIGNALPROCESS_CONSTVALUE_H

#include <cmath>
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

struct Complex {
public:
    float re;
    float im;

    Complex( float r = 0, float i = 0) : re(r), im(i) {}

    float amplitude() const {
        return std::sqrt((re * re) + (im * im) );
    }

    float phase() const {
        return std::atan2(im, re);
    }

#pragma region Math Operator
    Complex* multiply(const Complex & other) {
        float r = (re * other.re) - (im * other.im);
        float i = (re * other.im) - (im * other.re);

        re = r;
        im = i;

        return this;
    }

    Complex* add(const Complex & other) {
        re += other.re;
        im += other.im;

        return this;
    }

    Complex operator* (const Complex & other) const {
        float r = (re * other.re) - (im * other.im);
        float i = (re * other.im) - (im * other.re);

        return Complex(r, i);
    }

    Complex operator+ (const Complex & other) const
    {
        return Complex( re + other.re, im + other.im );
    }
#pragma endregion
};

extern const int BUFFER_SIZE = 8192;

#endif //AUDIOSIGNALPROCESS_CONSTVALUE_H
