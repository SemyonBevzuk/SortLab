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

using namespace std;

void InitParser(cmdline::parser& parser);

template <typename Type>
void GenerateVectorSortAndSaveStats(ofstream& file, Generators& gen, ISort<Type>& sortMethod, unsigned int size, double lb, double rb);

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
    unsigned int numBucket = parser.get<unsigned int>("numBucket");
    double lb = parser.get<double>("lb");
    double rb = parser.get<double>("rb");

    Generators generator;

    string title = "";
    if (!IsFileExists(filename))
    {
        title = "Method,Type,Status,Size,Time\n";
    }

    ofstream myfile;
    myfile.open(filename, ofstream::app);
    myfile << title;
    if (sortName == "Bubble") {
        BubbleSort<__int32> sort1;
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb);
        BubbleSort<__int64> sort2;
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb);
        BubbleSort<float> sort3;
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb);
        BubbleSort<double> sort4;
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb);
    }
    if (sortName == "Standart") {
        StandartSort<__int32> sort1;
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb);
        StandartSort<__int64> sort2;
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb);
        StandartSort<float> sort3;
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb);
        StandartSort<double> sort4;
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb);
    }
    if (sortName == "Merge") {
        MergeSort<__int32> sort1(kMerge);
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb);
        MergeSort<__int64> sort2(kMerge);
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb);
        MergeSort<float> sort3(kMerge);
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb);
        MergeSort<double> sort4(kMerge);
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb);
    }
    if (sortName == "Quick") {
        QuickSort<__int32> sort1;
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb);
        QuickSort<__int64> sort2;
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb);
        QuickSort<float> sort3;
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb);
        QuickSort<double> sort4;
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb);
    }
    if (sortName == "QuickLomuto") {
        QuickSortLomuto<__int32> sort1;
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb);
        QuickSortLomuto<__int64> sort2;
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb);
        QuickSortLomuto<float> sort3;
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb);
        QuickSortLomuto<double> sort4;
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb);
    }
    if (sortName == "SearchTree") {
        SearchTreeSort<__int32> sort1;
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb);
        SearchTreeSort<__int64> sort2;
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb);
        SearchTreeSort<float> sort3;
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb);
        SearchTreeSort<double> sort4;
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb);
    }
    if (sortName == "Heap") {
        HeapSort<__int32> sort1(dHeap);
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb);
        HeapSort<__int64> sort2(dHeap);
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb);
        HeapSort<float> sort3(dHeap);
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb);
        HeapSort<double> sort4(dHeap);
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb);
    }
    if (sortName == "BucketStandart") {
        BucketStandartSort<__int32> sort1(numBucket);
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb);
        BucketStandartSort<__int64> sort2(numBucket);
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb);
        BucketStandartSort<float> sort3(numBucket);
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb);
        BucketStandartSort<double> sort4(numBucket);
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb);
    }
    if (sortName == "BucketInsertion") {
        BucketInsertionSort<__int32> sort1(numBucket);
        GenerateVectorSortAndSaveStats<__int32>(myfile, generator, sort1, sizeArray, lb, rb);
        BucketInsertionSort<__int64> sort2(numBucket);
        GenerateVectorSortAndSaveStats<__int64>(myfile, generator, sort2, sizeArray, lb, rb);
        BucketInsertionSort<float> sort3(numBucket);
        GenerateVectorSortAndSaveStats<float>(myfile, generator, sort3, sizeArray, lb, rb);
        BucketInsertionSort<double> sort4(numBucket);
        GenerateVectorSortAndSaveStats<double>(myfile, generator, sort4, sizeArray, lb, rb);
    }
    myfile.close();
    return 0;
}

void InitParser(cmdline::parser& parser) {
    parser.add<string>("outFile", 'f', "Name of the output csv file", false, "test");
    parser.add<string>("sortName", 's', "Name of the sort", false, "QuickLomuto");
    parser.add<unsigned int>("sizeArray", 'n', "Size of the sort array", false, 10);
    parser.add<unsigned int>("kMerge", 'k', "k-Merge in MergeSort ", false, 5);
    parser.add<unsigned int>("dHeap", 'd', "d-heap in HeapSort", false, 3);
    parser.add<unsigned int>("numBucket", 'b', "Number of bucket in BucketSort", false, 10);
    parser.add<double>("lb", 'l', "Left border", false, 0);
    parser.add<double>("rb", 'r', "Right border", false, 10);
}

template <typename Type>
void GenerateVectorSortAndSaveStats(ofstream& file, Generators& gen, ISort<Type>& sortMethod, unsigned int size, double lb, double rb) {
    vector<Type> array(size);
    gen.FillVector(array, lb, rb);
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
    cout << "Type = " << array_type << endl << endl;

    file << sortMethod.GetSortName() << "," << array_type << "," << IsVectorsEqual(array, sort_array) << "," << size << "," << sortMethod.GetSortTime() << "\n";
}