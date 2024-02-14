#include "list.h"
#include "menu.h"

#include <iostream>

template <typename T>
void enterData(T& dataItem);


template <>
void enterData<int>(int& dataItem) {
    enteringNumber(1, 100, dataItem);
}

template <>
void enterData<std::string>(std::string& dataItem) {
    std::cout << "Введите короткую строку:  ";
    std::cin >> dataItem;
}


template <typename T>
void processList(list<T>& listEx, int& countItems) {
    int subOperation{ 0 };             
    T dataItem{};

    while (true) {
        printMenu(1);
        enteringNumber(0, 4, subOperation);
        switch (subOperation)
        {
        case 0:
            return;
        case 1:
            std::cout << (isEmpty(listEx) ? "Список пуст." : "Список не пуст.") << std::endl;
            break;
        case 2:
            std::cout << "Ввод значения элемента для добавления " << std::endl;
            enterData(dataItem);
            addItem(dataItem, listEx);
            break;
        case 3:
            std::cout << "Ввод значения элемента для удаления: " << std::endl;
            enterData(dataItem);
            deleteItem(dataItem, listEx);
            break;
        case 4:
            printStateList(listEx);
            break;
        default:
            break;
        }
    }
}

template void processList<int>(list<int>& listEx, int& countItems);
template void processList<std::string>(list<std::string>& listEx, int& countItems);
