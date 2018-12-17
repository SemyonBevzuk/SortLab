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
    Generators() {
        gen32.seed(time(NULL));
        gen64.seed(time(NULL));
    }

    void FillVector(std::vector<__int32>& array, const __int32 a = _I32_MIN, const __int32 b = _I32_MAX, std::string distribution = "uniform") {
        std::uniform_int_distribution<__int32> uid(a, b);
        for (unsigned int i = 0; i < array.size(); i++) {
            array[i] = uid(gen32);
        }
    }

    void FillVector(std::vector<__int64>& array, const __int64 a = _I64_MIN, const __int64 b = _I64_MAX, std::string distribution = "uniform") {
        std::uniform_int_distribution<__int64> uid(a, b);
        for (unsigned int i = 0; i < array.size(); i++) {
            array[i] = uid(gen64);
        }
    }

    void FillVector(std::vector<double>& array, const double a = 0, const double b = 1, std::string distribution = "uniform") {
        std::uniform_real_distribution<double> urd(a, b);
        double var = (a + (b - a) / 2.0);
        double sigma = 1;//pow((b - a) / 6.0, 1);
        std::normal_distribution<double> nd(var, sigma);
        for (unsigned int i = 0; i < array.size(); i++) {
            if (distribution == "uniform")
                array[i] = urd(gen64);
            else
                array[i] = nd(gen64);
        }
    }

    void FillVector(std::vector<float>& array, const float a = 0, const float b = 1, std::string distribution = "uniform") {
        std::uniform_real_distribution<float> urd(a, b);
        float var = (a + (b - a) / 2.0);
        float sigma = 1;// pow((b - a) / 6.0, 1);
        std::normal_distribution<float> nd(var, sigma);
        for (unsigned int i = 0; i < array.size(); i++) {
            if (distribution == "uniform")
                array[i] = urd(gen32);
            else
                array[i] = nd(gen32);
        }
    }
};