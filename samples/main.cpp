#include <iostream>
#include <cstdlib>

#include <vector>
#include <algorithm>

#include "generator.h"
#include "sorts.h"
#include "utilities.h"
#include "cmdline.h"
#include <fstream>
#include <type_traits>
#include <cmath>

using namespace std;

void InitParser(cmdline::parser& parser);

template <typename Type>
void GenerateVectorSortAndSaveStats(ofstream& file, Generators& gen, ISort<Type>& sortMethod, unsigned int size, double lb, double rb, string distribution);

int main(int argc, char** argv) {
    cmdline::parser parser;
    InitParser(parser);
    parser.parse_check(argc, argv);
    string filename = parser.get<string>("outFile");
    filename = filename + ".csv";
    string sortName = parser.get<string>("sortName");
    unsigned int sizeArray = parser.get<unsigned int>("sizeArray");
    unsigned int kMerge = parser.get<unsigned int>("kMerge");
    unsigned int dHeap = parser.get<unsigned int>("dHeap");
    double denominator = parser.get<double>("denominator");
    double lb = parser.get<double>("lb");
    double rb = parser.get<double>("rb");
    string distribution = parser.get<string>("distribution");

    Generators generator;

    string title = "";
    if (!IsFileExists(filename)) {
        title = "Method,Type,Status,Distribution,Size,Time\n";
    }

    ofstream myfile;
    myfile.open(filename, ofstream::app);
    myfile << title;
    if (sortName == "Bubble") {
        BubbleSort<__int32> sort1;
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb, distribution);
        BubbleSort<__int64> sort2;
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb, distribution);
        BubbleSort<float> sort3;
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb, distribution);
        BubbleSort<double> sort4;
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb, distribution);
    }
    if (sortName == "Standart") {
        StandartSort<__int32> sort1;
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb, distribution);
        StandartSort<__int64> sort2;
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb, distribution);
        StandartSort<float> sort3;
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb, distribution);
        StandartSort<double> sort4;
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb, distribution);
    }
    if (sortName == "Merge") {
        MergeSort<__int32> sort1(kMerge);
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb, distribution);
        MergeSort<__int64> sort2(kMerge);
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb, distribution);
        MergeSort<float> sort3(kMerge);
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb, distribution);
        MergeSort<double> sort4(kMerge);
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb, distribution);
    }
    if (sortName == "Quick") {
        QuickSort<__int32> sort1;
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb, distribution);
        QuickSort<__int64> sort2;
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb, distribution);
        QuickSort<float> sort3;
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb, distribution);
        QuickSort<double> sort4;
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb, distribution);
    }
    if (sortName == "QuickLomuto") {
        QuickSortLomuto<__int32> sort1;
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb, distribution);
        QuickSortLomuto<__int64> sort2;
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb, distribution);
        QuickSortLomuto<float> sort3;
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb, distribution);
        QuickSortLomuto<double> sort4;
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb, distribution);
    }
    if (sortName == "SearchTree") {
        SearchTreeSort<__int32> sort1;
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb, distribution);
        SearchTreeSort<__int64> sort2;
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb, distribution);
        SearchTreeSort<float> sort3;
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb, distribution);
        SearchTreeSort<double> sort4;
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb, distribution);
    }
    if (sortName == "Heap") {
        HeapSort<__int32> sort1(dHeap);
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb, distribution);
        HeapSort<__int64> sort2(dHeap);
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb, distribution);
        HeapSort<float> sort3(dHeap);
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb, distribution);
        HeapSort<double> sort4(dHeap);
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb, distribution);
    }
    if (sortName == "HeapStandart") {
        HeapStandartSort<__int32> sort1;
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb, distribution);
        HeapStandartSort<__int64> sort2;
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb, distribution);
        HeapStandartSort<float> sort3;
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb, distribution);
        HeapStandartSort<double> sort4;
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb, distribution);
    }
    if (sortName == "BucketStandart") {
        BucketStandartSort<__int32> sort1(denominator);
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb, distribution);
        BucketStandartSort<__int64> sort2(denominator);
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb, distribution);
        BucketStandartSort<float> sort3(denominator);
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb, distribution);
        BucketStandartSort<double> sort4(denominator);
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb, distribution);
    }
    if (sortName == "BucketStandartNormal") {
        double mean = (lb + (rb - lb) / 2.0);
        double sigma = (rb - lb) / 100.0;
        //BucketStandartNormalSort<__int32> sort1(mean, sigma, denominator);
        //GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb, distribution);
        //BucketStandartNormalSort<__int64> sort2(mean, sigma, denominator);
        //GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb, distribution);
        BucketStandartNormalSort<float> sort3(mean, sigma, denominator);
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb, distribution);
        BucketStandartNormalSort<double> sort4(mean, sigma, denominator);
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb, distribution);
    }
    if (sortName == "BucketInsertion") {
        BucketInsertionSort<__int32> sort1(denominator);
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb, distribution);
        BucketInsertionSort<__int64> sort2(denominator);
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb, distribution);
        BucketInsertionSort<float> sort3(denominator);
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb, distribution);
        BucketInsertionSort<double> sort4(denominator);
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb, distribution);
    }
    if (sortName == "BucketInsertioNormal") {
        double mean = (lb + (rb - lb) / 2.0);
        double sigma = (rb - lb) / 100.0;
        //BucketInsertioNormalnSort<__int32> sort1(mean, sigma, denominator);
        //GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb, distribution);
        //BucketInsertioNormalnSort<__int64> sort2(mean, sigma, denominator);
        //GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb, distribution);
        BucketInsertioNormalnSort<float> sort3(mean, sigma, denominator);
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb, distribution);
        BucketInsertioNormalnSort<double> sort4(mean, sigma, denominator);
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb, distribution);
    }
    if (sortName == "BucketInsertionSortAdaptiv") {
        BucketInsertionAdaptivSort<__int32> sort1;
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb, distribution);
        BucketInsertionAdaptivSort<__int64> sort2;
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb, distribution);
        BucketInsertionAdaptivSort<float> sort3;
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb, distribution);
        BucketInsertionAdaptivSort<double> sort4;
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb, distribution);
    }
    if (sortName == "Shell") {
        ShellSort<__int32> sort1;
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb, distribution);
        ShellSort<__int64> sort2;
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb, distribution);
        ShellSort<float> sort3;
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb, distribution);
        ShellSort<double> sort4;
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb, distribution);
    }
    if (sortName == "Counting") {
        CountingSort<__int32> sort1;
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb, distribution);
        CountingSort<__int64> sort2;
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb, distribution);
    }
    if (sortName == "Radix") {
        RadixSort<__int32> sort1;
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb, distribution);
        RadixSort<__int64> sort2;
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb, distribution);
    }
    myfile.close();
    return 0;
}

void InitParser(cmdline::parser& parser) {
    parser.add<string>("outFile", 'f', "Name of the output csv file", false, "test");
    parser.add<string>("sortName", 's', "Name of the sort", false, "BucketStandartNormal");
    parser.add<unsigned int>("sizeArray", 'n', "Size of the sort array", false, 1000);
    parser.add<unsigned int>("kMerge", 'k', "k-Merge in MergeSort ", false, 3);
    parser.add<unsigned int>("dHeap", 'd', "d-heap in HeapSort", false, 3);
    parser.add<double>("denominator", 'b', "Number of bucket in BucketSort = size/denominator, its a denominator", false, 100);
    parser.add<double>("lb", 'l', "Left border", false, 0);
    parser.add<double>("rb", 'r', "Right border", false, 10);
    parser.add<string>("distribution", 't', "Type of distribution: uniform, normal", false, "normal");
}

template <typename Type>
void GenerateVectorSortAndSaveStats(ofstream& file, Generators& gen, ISort<Type>& sortMethod, unsigned int size, double lb, double rb, string distribution) {
    vector<Type> array(size);
    gen.FillVector(array, lb, rb, distribution);
    cout << "\n\tRandom array:" << endl;
    PrintVector<Type>(array);
    vector<Type> sort_array = sortMethod.Sort(array);
    cout << "\n\t" << sortMethod.GetSortName() << ":" << endl;
    PrintVector<Type>(sort_array);
    cout << "Equal = " << IsVectorsEqual(array, sort_array) << endl;
    cout << "Time = " << sortMethod.GetSortTime() << endl;

    string array_type = "";
    if (std::is_same<Type, __int32>::value) array_type = "int32";
    if (std::is_same<Type, __int64>::value) array_type = "int64";
    if (std::is_same<Type, double>::value) array_type = "double";
    if (std::is_same<Type, float>::value) array_type = "float";
    cout << "Type = " << array_type << endl;
    cout << "Size = " << size << endl;
    cout << "Distribution = " << distribution << endl << endl;

    file << sortMethod.GetSortName() << "," << array_type << "," << IsVectorsEqual(array, sort_array) << "," << distribution << "," << size << "," << sortMethod.GetSortTime() << "\n";
}