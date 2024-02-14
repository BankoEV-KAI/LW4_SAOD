#pragma once
#include <string>

template<typename T>
struct list
{
    T data;
};

const int listSize{ 10 };
extern int countIntItems, countStringItems;
extern list<int> listInt[listSize];
extern list<std::string> listString[listSize];


template<typename T>
bool isInt(T& data);

template<typename T>
void initEmptyList();


template<typename T>
bool isFull(list<T>& listEx);

template<typename T>
bool isEmpty(list<T>& listEx);

template<typename T>
void printDataList(list<T>& listEx);

template<typename T>
void printStateList(list<T>& listEx);

template<typename T>
int searchItem(T dataItem, list<T>& listEx);

template<typename T>
void addItem(T dataItem, list<T>& listEx);

template<typename T>
void deleteItem(T dataItem, list<T>& listEx);

template <typename T>
void processList(list<T>& listEx, int& countItems);
