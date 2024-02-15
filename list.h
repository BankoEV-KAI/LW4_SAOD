#pragma once
#include <string>

const int listSize{ 10 };



template <typename T>
struct sturctList {
    T data[listSize];
    int count;
    
};

extern sturctList<int> listInt;
extern sturctList<std::string> listString;

template <typename T>
void processList(sturctList<T>& listEx);
template <typename T>
void printList(sturctList<T>& listEx);
template <typename T>
void addItem(sturctList<T>& listEx, T newData);
template <typename T>
bool isEmpty(const sturctList<T>& listEx);
template <typename T>
bool isFull(const sturctList<T>& listEx);

template <typename T>
void deleteItemByIndex(sturctList<T>& listEx, int index);
template <typename T>
void deleteItemByData(sturctList<T>& listEx, T deletedData);
template <typename T>
void deleteItem(sturctList<T>& listEx, int index);

template <typename T>
int searchItem(sturctList<T>& listEx, T searchData);


