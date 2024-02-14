//ЛР 4 по курсу САОД задание 1.3.2

#include "menu.h"
#include "list.h"

#include <iostream>





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
			//дестрой
			return 0;
		case 1: //int
            processList(*listInt, countIntItems);
			break;
		case 2: //string
			processList(*listString, countIntItems);
			break;
		default:
			break;
		}

	}

    return 0;
}
