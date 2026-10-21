//*****************************************************************************************************
//
//      File:                   sortedList.h
//
//      Student:                Cadence Seim
//
//      Assignment:             Assignment #9
//
//      Due:                    11/17/2025     
//          
//*****************************************************************************************************

#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stock.h"

//*****************************************************************************************************
template <typename T>
class SortedList
{
private:
    T* list;
    int capacity;
    int count;

    int partitionA(T arr[], int low, int high);
    int partitionD(T arr[], int low, int high);
    void swap(T& item1, T& item2);
    void quickSortA(T arr[], int low, int high);
    void quickSortD(T arr[], int low, int high);
    void selectionSortA(T arr[], int size);
    void selectionSortD(T arr[], int size);
    void heapSortA(T arr[], int n);
    void heapSortD(T arr[], int n);
    void heapifyA(T arr[], int n, int root);
    void heapifyD(T arr[], int n, int root);

public:
    SortedList(int size);
    ~SortedList();

    void insert(const T& item);
    void randomise();
    void selectionSortA();
    void selectionSortD();
    void quickSortA();
    void quickSortD();
    void display() const;
    void heapSortA();
    void heapSortD();
};

//*****************************************************************************************************
template <typename T>
SortedList<T>::SortedList(int size)
{
    capacity = size;
    count = 0;
    list = new T[size];
}

//*****************************************************************************************************
template <typename T>
SortedList<T>::~SortedList()
{
    delete[] list;
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::swap(T& item1, T& item2)
{
    T temp = item1;
    item1 = item2;
    item2 = temp;
}

//*****************************************************************************************************
template <typename T>
int SortedList<T>::partitionA(T arr[], int low, int high)
{
    T pivot = arr[(low + high) / 2];
    swap(arr[low], arr[(low + high) / 2]);
    int smallIndex = low;

    for (int i = low + 1; i <= high; ++i)
    {
        if (arr[i] < pivot)
        {
            ++smallIndex;
            swap(arr[smallIndex], arr[i]);
        }
    }
    swap(arr[low], arr[smallIndex]);
    return smallIndex;
}

//*****************************************************************************************************
template <typename T>
int SortedList<T>::partitionD(T arr[], int low, int high)
{
    T pivot = arr[(low + high) / 2];
    swap(arr[low], arr[(low + high) / 2]);
    int largeIndex = low;

    for (int i = low + 1; i <= high; ++i)
    {
        if (arr[i] > pivot)
        {
            ++largeIndex;
            swap(arr[largeIndex], arr[i]);
        }
    }
    swap(arr[low], arr[largeIndex]);
    return largeIndex;
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::quickSortA(T arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partitionA(arr, low, high);
        quickSortA(arr, low, pivot - 1);
        quickSortA(arr, pivot + 1, high);
    }
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::quickSortD(T arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partitionD(arr, low, high);
        quickSortD(arr, low, pivot - 1);
        quickSortD(arr, pivot + 1, high);
    }
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::selectionSortA(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        swap(arr[i], arr[minIndex]);
    }
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::selectionSortD(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] > arr[maxIndex])
                maxIndex = j;

        swap(arr[i], arr[maxIndex]);
    }
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::insert(const T& item)
{
    if (count == capacity)
    {
        int newCapacity = capacity + 10;
        T* newList = new T[newCapacity];

        for (int i = 0; i < count; i++)
            newList[i] = list[i];

        delete[] list;

        list = newList;
        capacity = newCapacity;
    }

    list[count++] = item;
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::randomise()
{
    srand(time(0));
    for (int i = 0; i < count; i++)
    {
        int r = rand() % count;
        swap(list[i], list[r]);
    }
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::selectionSortA()
{
    selectionSortA(list, count);
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::selectionSortD()
{
    selectionSortD(list, count);
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::quickSortA()
{
    quickSortA(list, 0, count - 1);
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::quickSortD()
{
    quickSortD(list, 0, count - 1);
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::display() const
{
    for (int i = 0; i < count; i++)
        std::cout << list[i] << std::endl;
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::heapifyA(T arr[], int n, int root)
{
    int largest = root; 
    int l = 2 * root + 1;
    int r = 2 * root + 2; 
    
    if ((l < n) && (arr[l] > arr[largest])) 
    {
        largest = l;
    }
    
    if ((r < n) && (arr[r] > arr[largest])) 
    {
        largest = r;
    }
    
    if (largest != root)
    {
        swap(arr[root], arr[largest]);
        heapifyA(arr, n, largest);
    }
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::heapifyD(T arr[], int n, int root)
{
    int smallest = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != root)
    {
        swap(arr[root], arr[smallest]);
        heapifyD(arr, n, smallest);
    }
}


//*****************************************************************************************************
template <typename T>
void SortedList<T>::heapSortA(T arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) 
    { 
        heapifyA(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) 
    { 
        swap(arr[0], arr[i]); 
        heapifyA(arr, i, 0); 
    }
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::heapSortD(T arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyD(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapifyD(arr, i, 0);
    }
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::heapSortA()
{
    heapSortA(list, count);
}

//*****************************************************************************************************
template <typename T>
void SortedList<T>::heapSortD()
{
    heapSortD(list, count);
}

//*****************************************************************************************************
#endif
