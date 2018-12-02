#pragma once
#include <vector>
#include <random>  
#include <ctime>
#include <iostream>

class Generators {
private:
    std::mt19937 gen32;
    std::mt19937_64 gen64;
public:
    Generators()
    {

        gen32.seed(time(NULL));
        gen64.seed(time(NULL));
    }

    void FillVector(std::vector<__int32>& array, const __int32 a = _I32_MIN, const __int32 b = _I32_MAX)
    {
        std::uniform_int_distribution<__int32> uid(a, b);
        for (unsigned int i = 0; i < array.size(); i++) {
            array[i] = uid(gen32);
        }
    }

    void FillVector(std::vector<__int64>& array, const __int64 a = _I64_MIN, const __int64 b = _I64_MAX) {
        std::uniform_int_distribution<__int64> uid(a, b);
        for (unsigned int i = 0; i < array.size(); i++) {
            array[i] = uid(gen64);
        }
    }

    void FillVector(std::vector<double>& array, const double a = 0, const double b = 1) {
        std::uniform_real_distribution<double> urd(a, b);
        for (unsigned int i = 0; i < array.size(); i++) {
            array[i] = urd(gen64);
        }
    }

    void FillVector(std::vector<float>& array, const float a = 0, const float b = 1) {
        std::uniform_real_distribution<float> urd(a, b);
        for (unsigned int i = 0; i < array.size(); i++) {
            array[i] = urd(gen32);
        }
    }
};