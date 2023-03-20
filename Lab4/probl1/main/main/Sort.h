#pragma once
#include <initializer_list>

class Sort
{
private:

    int size, list[1000];
    int QuickSortPivot(int left, int right, bool ascendent);
    void QuickSortPartition(int left, int right, bool ascendent);

public:

    Sort(int size, int min, int max);
    Sort(const std::initializer_list<int>& list);
    Sort(int vector[], int size);
    Sort(int size, ...);
    Sort(const char list[]);

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

};