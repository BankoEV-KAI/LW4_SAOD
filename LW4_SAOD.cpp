//ЛР 4 по курсу САОД задание 1.3.2

#include "menu.h"
#include "list.h"
#include <iostream>


sturctList<std::string> listString;
sturctList<int> listInt;

int main()
{
    setlocale(LC_ALL, "ru");
    int operation{ 0 };
    int value{ 0 };
	

	while (true) {
		printMenu(0);
		enteringNumber(0, 2, operation);
		switch (operation)
		{
		case 0:
			return 0;
		case 1: //int
            processList(listInt);
			break;
		case 2: //string
			processList(listString);
			break;
		default:
			break;
		}

	}

    return 0;
}
