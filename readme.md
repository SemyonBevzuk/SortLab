# Описание директорий
- **bin** - содержит исполняемый файл *sample_lab.exe*
- **experiments** - содержит результаты экспериментов и скрипты для построения графиков
- **include** - содержит исходнники с сортировками, генераторами и вспомогательными функциями
- **samples** - содержит пример использования функций сортировок и генераторов

# Описание include
- **base_sort.h** - общий интерфейс сортировок
- **cmdline.h** - парсер командной строки
- **generator.h** - содержит реализацию генераторов случайных массивов
- **sorts.h** - содержит реализацию разлинчный сортировок
- **utilities.h** - содержит вспомогательный функции (печать, наличие файла в директории, сравнение двух массивов)

# Реализованные сортировки в sorts.h
- BubbleSort
- StandartSort на основе std::sort()
- k-MergeSort
- QuickSort с разбиением Хоара и устранением хвостовой рекурсии
- QuickSort с разбиением Ломуто и устранением хвостовой рекурсии
- SearchTreeSort на основе multiset
- d-HeapSort
- BucketStandartSort с указанием числа карманов
- BucketInsertionSort с указанием числа карманов
- BucketInsertionAdaptivSort
- CountingSort только для int32 и int64

# Реализованные генераторы в generator.h
- Генератор чисел *int32* в диапазоне от *a* до *b*
- Генератор чисел *int64* в диапазоне от *a* до *b*
- Генератор чисел *double* в диапазоне от *a* до *b*
- Генератор чисел *float* в диапазоне от *a* до *b*

# Аргументы sample_lab
- *-f* - имя файла .csv со статистикой
- *-s* - имя сортирвоки
- *-n* - размер массива для генерации и сортировки
- *-k* - параметр *k* для k-MergeSort
- *-f* - парамтер *d* для d-HeapSort
- *-b* - число карманов *b* для BucketStandartSort, BucketInsertionSort
- *-lb* - левая граница для генератора случайных чисел
- *-rb* - правая граница для генератора случайных чисел

# Описание скиптов в *experiments*
- *plot_all_sorts.py* - строит общий график по всем сортировкам
- *plot_method_with_dif_types.py* - строит график для конкретной сортировки, её нужно указать в качестве параметра, для разных типов данных
- *plot_buckets.py* - строит график для сравнения BucketStandartSort, BucketInsertionSort, BucketInsertionAdaptivSort
