#pragma once
#include "base_sort.h"
#include <vector>
#include <algorithm>
#include <omp.h>
#include <map>
#include <set>
#include <random>  
#include <ctime>
#include <string>

using namespace std;

// O(n^2)
template <typename Type>
class BubbleSort : public ISort<Type> {
public:
    BubbleSort() {}

    string GetSortName() { return "Bubble"; };

    vector<Type> Sort(const vector<Type>& array_t) {
        vector<Type> array_out = array_t;

        double start_time = omp_get_wtime();
        for (unsigned int i = array_out.size() - 1; i > 0; i--)
            for (unsigned int j = 0; j < i; j++)
                if (array_out[j] > array_out[j + 1]) {
                    swap(array_out[j], array_out[j + 1]);
                }
        sort_time = omp_get_wtime() - start_time;

        return array_out;
    }
};

// O(n*log(n)) в среднем
template <typename Type>
class StandartSort : public ISort<Type>{
public:
    string GetSortName() { return "Standart"; };

    vector<Type> Sort(const vector<Type>& array_t) {
        vector<Type> array_out = array_t;

        double start_time = omp_get_wtime();
        sort(array_out.begin(), array_out.end());
        sort_time = omp_get_wtime() - start_time;

        return array_out;
    }
};

// O(n*log(n)) всегда, память O(n) дополнительно
template <typename Type>
class MergeSort : public ISort<Type> {
private:
    unsigned int k;

    template <typename Type>
    void BubbleSort(vector<Type>& buf, size_t left, size_t right) {
        for (unsigned int i = right; i > left; i--)
            for (unsigned int j = left; j < i; j++)
                if (buf[j] > buf[j + 1]) {
                    swap(buf[j], buf[j + 1]);
                }
    }

    template <typename Type>
    void Merge_Sort(vector<Type>& buf, size_t left, size_t right) {
        if ((right - left) > k) {
            size_t middle = left + (right - left) / 2;

            Merge_Sort(buf, left, middle);
            Merge_Sort(buf, middle + 1, right);
            merge(buf, left, right, middle);
        }
        else {
            BubbleSort(buf, left, right);
        }
    }

    template <typename Type>
    void merge(vector<Type>& buf, size_t left, size_t right, size_t middle) {
        if (left >= right || middle < left || middle > right) return;
        if (right == left + 1 && buf[left] > buf[right]) {
            swap(buf[left], buf[right]);
            return;
        }

        vector<Type> tmp(&buf[left], &buf[right] + 1);

        for (size_t i = left, j = 0, k = middle - left + 1; i <= right; ++i) {
            if (j > middle - left) {
                buf[i] = tmp[k++];
            }
            else if (k > right - left) {
                buf[i] = tmp[j++];
            }
            else {
                buf[i] = (tmp[j] < tmp[k]) ? tmp[j++] : tmp[k++];
            }
        }
    }

public:
    MergeSort(int _k = 1) {
        k = _k;
    }

    string GetSortName() { return "Merge_" + to_string(k); };

    vector<Type> Sort(const vector<Type>& array_t) {
        double start_time = omp_get_wtime();
        vector<Type> array_out = array_t; // требует доп память 
        Merge_Sort(array_out, 0, array_out.size() - 1);
        sort_time = omp_get_wtime() - start_time;

        return array_out;
    }
};

// O(n*log(n)) в среднем, неустойчивая
template <typename Type>
class QuickSort : public ISort<Type> {
private:
    std::mt19937 gen;

    template <typename Type>
    int Partition(vector<Type>& a, int low, int high) {
        std::uniform_int_distribution<unsigned int> uid(low, high);
        Type pivot = a[uid(gen)];
        int i = low - 1, j = high + 1;

        while (true) {
            do {
                i++;
            } while (a[i] < pivot);
            do {
                j--;
            } while (a[j] > pivot);
            if (i >= j)
                return j;

            swap(a[i], a[j]);
        }
    }

    template <typename Type>
    void Quick_Sort(vector<Type>& a, int low, int high) {
        /* if (low < high) {
             unsigned int pi = Partition(a, low, high);
             Quick_Sort(a, low, pi);
             Quick_Sort(a, pi+1, high);
             }
             */
        while (low < high) {
            unsigned int p = Partition(a, low, high);
            if (p - low <= high - p) {
                Quick_Sort(a, low, p);
                low = p + 1;
            }
            else {
                Quick_Sort(a, p, high);
                high = p;
            }
        }
    }
public:
    string GetSortName() { return "Quick"; };

    vector<Type> Sort(const vector<Type>& array_t) {
        vector<Type> array_res = array_t;

        double start_time = omp_get_wtime();
        gen.seed(time(NULL));
        Quick_Sort(array_res, 0, array_res.size() - 1);
        sort_time = omp_get_wtime() - start_time;

        return array_res;
    }
};

// O(n*log(n)) в среднем, неустойчивая
template <typename Type>
class QuickSortLomuto : public ISort<Type> {
private:
    std::mt19937 gen;

    template <typename Type>
    int Partition(vector<Type>& a, int low, int high) {
        Type pivot = a[high];
        int i = low;

        for (int j = low; j < high; j++) {
            if (a[j] <= pivot) {
                swap(a[i], a[j]);
                i++;
            }
        }
        swap(a[i], a[high]);
        return i;
    }

    template <typename Type>
    void Quick_Sort(vector<Type>& a, int low, int high) {
        /*if (low < high) {
            unsigned int pi = Partition(a, low, high);
            Quick_Sort(a, low, pi-1);
            Quick_Sort(a, pi + 1, high);
            }*/
        while (low < high) {
            int p = Partition(a, low, high);
            if (p - low <= high - p) {
                Quick_Sort(a, low, p);
                low = p + 1;
            }
            else {
                Quick_Sort(a, p, high);
                high = p - 1;
            }
        }
    }
public:
    string GetSortName() { return "QuickLomuto"; };

    vector<Type> Sort(const vector<Type>& array_t) {
        vector<Type> array_out = array_t;

        double start_time = omp_get_wtime();
        //gen.seed(time(NULL));
        Quick_Sort(array_out, 0, array_out.size()-1);
        sort_time = omp_get_wtime() - start_time;

        return array_out;
    }
};

// O(n*log(n)) в среднем - вставка n элементов за log, доп память на структуру
template <typename Type>
class SearchTreeSort : public ISort<Type> {
public:
    string GetSortName() { return "SearchTree"; };

    vector<Type> Sort(const vector<Type>& array_t) {

        double start_time = omp_get_wtime();
        multiset<Type> tree;
        vector<Type> array_out;
        for (unsigned int i = 0; i < array_t.size(); i++) {
            tree.insert(array_t[i]);
        }
        for (multiset<Type>::iterator ptr = tree.begin(); ptr != tree.end(); ++ptr) {
            array_out.push_back(*ptr);
        }
        sort_time = omp_get_wtime() - start_time;

        return array_out;
    }
};

// O(n(log(n)) в среднем, неустойчивая
template <typename Type>
class HeapSort : public ISort<Type> {
private:
    unsigned int d;

    unsigned int Child(unsigned int i, unsigned int index) {
        return (d*i + index + 1);
    }
    unsigned int Parent(unsigned int i) {
        return ((i - 1) / d);
    }

    template <typename Type>
    void MaxHeapify(unsigned int index, unsigned int size, vector<Type>& tree) {
        unsigned int final = index;
        for (unsigned int i = 0; i < d; ++i) {
            unsigned int childIndex = Child(index, i);
            if (childIndex < size
                && tree.at(childIndex) > tree.at(final))
                final = childIndex;
        }

        if (final != index) {
            swap(tree[index], tree[final]);
            MaxHeapify(final, size, tree);
        }
    }

    template <typename Type>
    void BuildMax(vector<Type>& array) {
        unsigned int size = array.size();
        for (unsigned int i = (unsigned int)size / d - 1; i > 0; i--)
            MaxHeapify(i, size, array);
        MaxHeapify(0, size, array);
    }

    template <typename Type>
    void MaxHeapSort(vector<Type>& in) {
        if (in.empty())
            return;

        BuildMax(in);

        int heapSize = in.size();
        while (heapSize > 0) {
            swap(in[0], in[heapSize - 1]);
            heapSize--;
            MaxHeapify(0, heapSize, in);
        }
    }

public:
    string GetSortName() { return "Heap_" + to_string(d); };

    HeapSort(unsigned int _d = 2) {
        d = _d;
    }

    vector<Type> Sort(const vector<Type>& array_t) {
        vector<Type> array_out = array_t;

        double start_time = omp_get_wtime();
        MaxHeapSort(array_out);
        sort_time = omp_get_wtime() - start_time;

        return array_out;
    }
};

// O(n) - линейная в среднем при n ~ k
template <typename Type>
class BucketStandartSort : public ISort<Type> {
private:
    unsigned int numBuckets;

    template <typename Type>
    vector<Type> BucketSort(const vector<Type>& a) {
        vector<Type> res;
        Type minElement = a[0];
        Type maxElement = a[0];
        for (unsigned int i = 0; i < a.size(); i++) {
            minElement = min(minElement, a[i]);
            maxElement = max(maxElement, a[i]);
        }
        Type range = maxElement - minElement;
        vector<vector<Type>> buckets(numBuckets, vector<Type>());
        for (unsigned int i = 0; i < a.size(); i++) {
            unsigned int index = floor(((a[i] - minElement) / (range + 1.))*numBuckets);
            buckets[index].push_back(a[i]);
        }
        for (unsigned int i = 0; i < buckets.size(); i++) {
            sort(buckets[i].begin(), buckets[i].end());
        }
        for (unsigned int i = 0; i < buckets.size(); i++) {
            for (unsigned int j = 0; j < buckets[i].size(); j++) {
                res.push_back(buckets[i][j]);
            }
        }
        return res;
    }

public:
    string GetSortName() { return "BucketStandart_" + to_string(numBuckets); };

    BucketStandartSort(unsigned int _numBuckets = 10) {
        numBuckets = _numBuckets;
    }

    vector<Type> Sort(const vector<Type>& array_t) {
        vector<Type> array_out;

        double start_time = omp_get_wtime();
        array_out = BucketSort(array_t);
        sort_time = omp_get_wtime() - start_time;

        return array_out;
    }
};

// O(n) - линейная в среднем при n ~ k
template <typename Type>
class BucketInsertionSort : public ISort<Type>  {
private:
    unsigned int numBuckets;

    template <typename Type>
    void Insertion_sort(vector<Type>& a) {
        unsigned int n = a.size();
        for (int i = 1; i<n; i++) {
            Type key = a[i];
            int j = i - 1;
            while (j >= 0 && a[j]>key) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }
    }

    template <typename Type>
    vector<Type> BucketSort(const vector<Type>& a) {
        vector<Type> res;
        Type minElement = a[0];
        Type maxElement = a[0];
        for (unsigned int i = 0; i < a.size(); i++) {
            minElement = min(minElement, a[i]);
            maxElement = max(maxElement, a[i]);
        }
        Type range = maxElement - minElement;
        vector<vector<Type>> buckets(numBuckets, vector<Type>());
        for (unsigned int i = 0; i < a.size(); i++) {
            unsigned int index = floor(((a[i] - minElement) / (range + 1.))*numBuckets);
            buckets[index].push_back(a[i]);
        }
        for (unsigned int i = 0; i < buckets.size(); i++) {
            Insertion_sort(buckets[i]);
        }
        for (unsigned int i = 0; i < buckets.size(); i++) {
            for (unsigned int j = 0; j < buckets[i].size(); j++) {
                res.push_back(buckets[i][j]);
            }
        }
        return res;
    }

public:
    string GetSortName() { return "BucketInsertion_" + to_string(numBuckets); };

    BucketInsertionSort(unsigned int _numBuckets = 10) {
        numBuckets = _numBuckets;
    }

    vector<Type> Sort(const vector<Type>& array_t) {
        vector<Type> array_out;

        double start_time = omp_get_wtime();
        array_out = BucketSort(array_t);
        sort_time = omp_get_wtime() - start_time;

        return array_out;
    }
};

// O(n) - линейная в среднем при n ~ k
template <typename Type>
class BucketInsertionAdaptiv : public ISort<Type> {
private:
    unsigned int numBuckets;

    template <typename Type>
    void Insertion_sort(vector<Type>& a) {
        unsigned int n = a.size();
        for (int i = 1; i<n; i++) {
            Type key = a[i];
            int j = i - 1;
            while (j >= 0 && a[j]>key) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }
    }

    template <typename Type>
    vector<Type> BucketSort(const vector<Type>& a) {
        numBuckets = a.size();
        vector<Type> res;
        Type minElement = a[0];
        Type maxElement = a[0];
        for (unsigned int i = 0; i < a.size(); i++) {
            minElement = min(minElement, a[i]);
            maxElement = max(maxElement, a[i]);
        }
        Type range = maxElement - minElement;
        vector<vector<Type>> buckets(numBuckets, vector<Type>());
        for (unsigned int i = 0; i < a.size(); i++) {
            unsigned int index = floor(((a[i] - minElement) / (range + 1.))*numBuckets);
            buckets[index].push_back(a[i]);
        }
        for (unsigned int i = 0; i < buckets.size(); i++) {
            Insertion_sort(buckets[i]);
            //sort(buckets[i].begin(), buckets[i].end());
        }
        for (unsigned int i = 0; i < buckets.size(); i++) {
            for (unsigned int j = 0; j < buckets[i].size(); j++) {
                res.push_back(buckets[i][j]);
            }
        }
        return res;
    }

public:
    string GetSortName() { return "BucketInsertionAdaptiv"; };

    vector<Type> Sort(const vector<Type>& array_t) {
        vector<Type> array_out;

        double start_time = omp_get_wtime();
        array_out = BucketSort(array_t);
        sort_time = omp_get_wtime() - start_time;

        return array_out;
    }
};