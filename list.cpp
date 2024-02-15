#include "list.h"
#include <iostream>


template bool isEmpty<int>(const sturctList<int>& listEx);
template void printList<int>(sturctList<int>& listEx);
template void addItem<int>(sturctList<int>& listEx, int newData);
template void deleteItem<int>(sturctList<int>& listEx, int index);
template void deleteItemByIndex<int>(sturctList<int>& listEx, int index);
template void deleteItemByData<int>(sturctList<int>& listEx, int data);
template int searchItem<int>(sturctList<int>& listEx, int data);


template bool isEmpty<std::string>(const sturctList<std::string>& listEx);
template void printList<std::string>(sturctList<std::string>& listEx);
template void addItem<std::string>(sturctList<std::string>& listEx, std::string newData);
template void deleteItem<std::string>(sturctList<std::string>& listEx, int index);
template void deleteItemByIndex<std::string>(sturctList<std::string>& listEx, int index);
template void deleteItemByData<std::string>(sturctList<std::string>& listEx, std::string data);
template int searchItem<std::string>(sturctList<std::string>& listEx, std::string data);

template <typename T>
bool isFull(const sturctList<T>& listEx) {
	return listEx.count == listSize;
}

template <typename T>
bool isEmpty(const sturctList<T>& listEx) {
	return listEx.count == 0;
}

template <typename T>
void addItem(sturctList<T>& listEx, T newData) {
    if (isFull(listEx)) {
        std::cerr << "Список переполнен. Добавление элемента невозможно." << std::endl;
        return;
    }
    if (isEmpty(listEx)) {
        listEx.data[0] = newData;
        listEx.count++;
        std::cout << "Список пуст. Элемент " << newData << " добавлен в начало списка." << listEx.count << std::endl;
        return;
    }

    for (int i{ 0 }; i < listEx.count; i++) {
        if (listEx.data[i] > newData) {
            for (int j{ listEx.count - 1 }; j >= i; j--) {
                listEx.data[j + 1] = listEx.data[j];
            }
            listEx.data[i] = newData;
            std::cout << "Элемент " << newData << " добавлен в список. На позицию " << i << " (нумерация позиций с нуля)" << std::endl;
            listEx.count++;
            return;
        }
    }
    listEx.data[listEx.count] = newData;
    listEx.count++;
    std::cout << "Элемент " << newData << " добавлен в список. На позицию " << listEx.count << " (нумерация позиций с нуля)" << std::endl;

}

template <typename T>
void deleteItem(sturctList<T>& listEx, int index) {
    for (int j{ index }; j < listEx.count - 1; j++) {
        listEx.data[j] = listEx.data[j + 1];
    }
    listEx.count--;
}

template <typename T>
int searchItem(sturctList<T>& listEx, T searchData) {
    if (isEmpty(listEx)) {
        return -2;
    }
    for (int i{ 0 }; i < listEx.count; i++) {
        if (listEx.data[i] == searchData) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void deleteItemByIndex(sturctList<T>& listEx, int index) {
    if (0 <= index && index < listEx.count) {
        std::cout << "Был удален элемент: "<< listEx.data[index] <<", расположенный на позиции: " << index  << std::endl;
        deleteItem(listEx, index);
        return;
    }
    std::cerr << "Передан некорректный индекс элемента. Удаление не бвло совершено" << std::endl;
}

template <typename T>
void deleteItemByData(sturctList<T>& listEx, T deletedData) {
    int index = searchItem(listEx, deletedData);
    if (index == -2) {
        std::cout << "Список пуст. Удаление невозможно" << std::endl;
        return;
    }
    if (index == -1) {
        std::cout << "Заданный элемент отсутствует в списке. Удаление невозможно" << std::endl;
        return;
    }
    std::cout << "Был удален элемент: " << deletedData << ", расположенный на позиции: " << index << std::endl;
    deleteItem(listEx, index);
}


template <typename T>
void printList(sturctList<T>& listEx) {
    if (isEmpty(listEx)) {
        std::cout << "Список пуст. " << std::endl;
        return;
    }
    std::cout << "Элементы списка: (";
    int i{ 0 };
    while (i != listEx.count) {
        std::cout << listEx.data[i];
        if (i != listEx.count - 1) {
            std::cout << "; ";
        }
        i++;
    }
    std::cout << "), заполненные позиции списка : " << listEx.count << "/" << listSize << std::endl;
}




template bool isFull<int>(const sturctList<int>& listEx);
template bool isFull<std::string>(const sturctList<std::string>& listEx);