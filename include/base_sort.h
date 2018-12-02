#pragma once
#include <vector>
#include <omp.h>

template <typename Type>
class ISort {
protected:
    double sort_time;
public:

    virtual std::vector<Type> Sort(const std::vector<Type>& array_t) = 0;

    double GetSortTime() { return sort_time; };

    virtual std::string GetSortName() = 0;
};