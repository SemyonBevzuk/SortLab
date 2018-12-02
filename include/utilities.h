#pragma once
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

template <typename Type>
void PrintVector(vector<Type>& a) {
    if (a.size() < 100) {
        cout << "Vector: " << endl;
        for (unsigned int i = 0; i < a.size(); i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    else
    {
        cout << "Too big..." << endl;
    }
}

template <typename Type>
bool IsVectorsEqual(vector<Type>& a, vector<Type>& b) { // пусть a - исходный, b - после сортировки
    if (a.size() != b.size()){
        return false;
    }
    vector<Type> a_sort = a;
    sort(a_sort.begin(), a_sort.end());
    if (equal(a_sort.begin(), a_sort.end(), b.begin())){
        return true;
    }
    else{
        return false;
    }
}

bool IsFileExists(string file_name) {
    ifstream file;
    file.open(file_name);
    if (!file) {
        return false;
    }
    else{
        return true;
    }

}