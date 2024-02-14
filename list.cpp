#include "list.h"
#include <iostream>


//дописать элементы для отдельных типов 
int countIntItems, countStringItems;
list<int> listInt[listSize];
list<std::string> listString[listSize];



template<typename T>
void initEmptyList() {
    countIntItems = 0;
    countStringItems = 0;
}

template <typename T>
bool isInt(T dataItem) {
    return false;
}

template <>
bool isInt<int>(int dataItem) {
    return true;
}

template <>
bool isInt<std::string>(std::string dataItem) {
    return false;
}


template<typename T>
bool isFull(list<T>& listEx) {
    return isInt(listEx->data) ? (countIntItems == listSize) : (countStringItems == listSize);
}

template<typename T>
bool isEmpty(list<T>& listEx) {
    return isInt(&listEx.data) ? (countIntItems == 0) : (countStringItems == 0);
}

template<typename T>
void printDataList(list<T>& listEx) {
    if (isEmpty<T>(listEx)) {
        std::cout << " список пуст" << std::endl;
        return;
    }
    else if (isFull<T>(listEx)) {
        std::cout << " список заполнен полностью. Элементы списка: (";
    }
    int i{ 0 }; int countItems{ 0 };
    isInt(listEx.data) ? countItems = countIntItems : countItems = countStringItems;
    while (i != countItems) {
        std::cout << (T)listEx.data; 
        if (i != countItems) {
            std::cout << "; ";
        }
        i++;
    }
    std::cout << "), количество элементов: " << countItems << "/" << listSize << std::endl;
}

template<typename T>
void printStateList(list<T>& listEx) {
    std::cout << "Состояние линейного списка: ";
    if (!isEmpty<T>()) {
        std::cout << "характеристики списка: ";
        printDataList<T>(listEx);
    }
    else {
        std::cout << "список пуст.";
    }
}

template<typename T>
int searchItem(T dataItem, list<T>& listEx) {
    if (isEmpty<T>(listEx)) {
        return -1;
    }
    int countItems{ 0 };
    isInt(listEx.data) ? countItems = countIntItems : countItems = countStringItems;
    for (int i{ 0 }; i < countItems; i++) {
        if (listEx[i].data == dataItem) {
            return i;
        }
    }
    return -1;
}

template<typename T>
void addItem(T dataItem, list<T>& listEx) {
    if (isFull<T>(listEx)) {
        std::cout << "Список переполнен, добавление невозможно." << std::endl;
        return;
    }
    if (isEmpty<T>(listEx)) {
        listEx[0].data = dataItem;
        std::cout << "Список был пуст, элемент был добавлен в начало списка. " << std::endl;
        return;
    }
    int countItems{ 0 };
    isInt(listEx.data) ? countItems = countIntItems : countItems = countStringItems;
    for (int i{ 0 }; i < countItems; i++) {
        if (dataItem < listEx[i].data) {
            if (i == countItems - 1) {
                listEx[i + 1].data = dataItem;
            }
            else {
                for (int j{ countItems }; j > i; j--) { //сдвиг элементов
                    listEx[j].data = listEx[j - 1].data;
                }
                listEx[i].data = dataItem;
            }
            std::cout << "Заданный элемент был добавлен на позицию: " << i << " (нумерация списка идет с нуля). " << std::endl;
            printStateList<T>(listEx);
        }
    }
}

template<typename T>
void deleteItem(T dataItem, list<T>& listEx) {
    int index = searchItem<T>(dataItem, listEx);
    int countItems{ 0 };
    isInt(listEx.data) ? countItems = countIntItems : countItems = countStringItems;
    if (index == -1) {
        std::cerr << "Error" << std::endl;
    }
    else {
        for (int j{ index }; j < countItems; j++) {
            listEx[j].data = listEx[j + 1].data;
        }
        std::cout << "Заданный элемент был удален с позиции: " << index << " (нумерация списка идет с нуля). " << std::endl;
        printStateList<T>();
    }
}

template bool isEmpty<int>(list<int>& listEx);
template bool isEmpty<std::string>(list<std::string>& listEx);

template <>
bool isFull<std::string>(list<std::string>& listEx) {
    return countStringItems == listSize;
}

template <>
bool isFull<int>(list<int>& listEx) {
    return countIntItems == listSize;
}

template <>
void printDataList<std::string>(list<std::string>& listEx) {
    return;
}

template <>
void printDataList<int>(list<int>& listEx) {
    return;
}

template <>
void printStateList<std::string>(list<std::string>& listEx) {
    return;
}

template <>
void printStateList<int>(list<int>& listEx) {
    return;
}

template <>
void addItem<std::string>(std::string dataItem, list<std::string>& listEx) {
    return;
}

template <>
void addItem<int>(int dataItem, list<int>& listEx) {
    return;
}

template <>
void deleteItem<std::string>(std::string dataItem, list<std::string>& listEx) {
    return;
}

template <>
void deleteItem<int>(int dataItem, list<int>& listEx) {
    return;
}