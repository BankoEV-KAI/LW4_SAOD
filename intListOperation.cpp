#include "list.h"
#include "menu.h"

#include <iostream>
#include <string>





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
void processList(sturctList<T>& listEx) {
    int subOperation{ 0 }; int index{ 0 };
    T dataItem{};

    while (true) {
        printMenu(1);
        enteringNumber(0, 5, subOperation);
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
            addItem(listEx,dataItem);
            printList(listEx);
            break;
        case 3:
            printMenu(2);
            enteringNumber(0, 2, subOperation);
            switch (subOperation)
            {
            case 0:
                break;
            case 1:
                std::cout << "Ввод индекса элемента для удаления: " << std::endl;
                enteringNumber(0, listEx.count - 1, index);
                deleteItemByIndex(listEx, index);
                break;
            case 2:
                std::cout << "Ввод значения элемента для удаления: " << std::endl;
                enterData(dataItem);
                deleteItemByData(listEx, dataItem);
                break;
            default:
                break;
            }
            
            printList(listEx);
            break;
        case 4:
            printMenu(3);
            enteringNumber(0, 2, subOperation);
            switch (subOperation)
            {
            case 0:
                break;
            case 1:
                printList(listEx);
                std::cout << "Ввод индекса элемента для поиска: " << std::endl;
                int index;
                enteringNumber(0, listEx.count - 1, index);
                std::cout << "Значение элемента по заданному индексу: " << listEx.data[index] << std::endl;
                break;
            case 2:
                printList(listEx);
                std::cout << "Ввод значения элемента для поиска: " << std::endl;
                enterData(dataItem);
                index = searchItem(listEx, dataItem);
                (index != -1 && index != -2) ? std::cout << "Элемент найден на позиции: " << index << std::endl : std::cout << "Искомый элемент отсутствует в списке." << std::endl;
                break;
            default:
                break;
            }
            break;
        case 5:
            printList(listEx);
            break;
        
        default:
            break;
        }
    }
}

template void processList<int>(sturctList<int>& listEx);
template void processList<std::string>(sturctList<std::string>& listEx);
