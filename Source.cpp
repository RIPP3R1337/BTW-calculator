#include <iostream>
#include <cmath>
#include <string>
#include "round.h"
#include "positive.h"




int main()
{
	char restart;

	do {
#ifdef _WIN32
		system("cls");
#else
		system("clear"); // ie Linux or MacOS
#endif 


		
		double prijs;
		char omrekenen;

		std::cout << "Would you like to include or exclude tax? (I/E): ";
		std::cin >> omrekenen;
		// convert to lowercase, and then convert back to a char type (as the tolower() function returns an integer)
		omrekenen = char(tolower(omrekenen));
		// check that the user entered i or e
		if (omrekenen != 'i' && omrekenen != 'e') {
			std::cout << "Please enter I/E. You entered: " << omrekenen << "." << std::endl;
		}

		std::cout << "Enter your amount € ";
		std::cin >> prijs;
		// check if prijs is a valid positive number
		if (!isPositiveDouble(prijs)) {
			std::cout << "Please enter a positive number. You entered: " << prijs << "." << std::endl;
		}

#ifdef _WIN32
		system("cls");
#else // ie Linux or MacOS
		system("clear");
#endif

		switch (omrekenen)
		{ // since we converted omrekenen to be lowercase no matter what, we don't need a separate case for 'e' and 'E', etc
		case 'e':
			std::cout << "You entered " << prijs << " Euro\n\n";
			std::cout << "21% TAX = +" << roundToTwoDecimalPlaces(prijs * 21 / 100) << " Euro\n\n";
			std::cout << "This amount is: " << roundToTwoDecimalPlaces(prijs * 1.21) << " Euro including TAX\n\n";
			break;
		case 'i':
			std::cout << "You entered " << prijs << " Euro\n\n";
			std::cout << "21% TAX = -" << roundToTwoDecimalPlaces(prijs * 21 / 121) << " Euro\n\n";
			std::cout << "This amount is: " << roundToTwoDecimalPlaces(prijs / 1.21) << " Euro excluding TAX\n\n";
			break;
		default:
			std::cout << "[ERROR] Not a valid value or another error has occured!\n";
			
		}


		std::cout << "\n\nWould you like to calculate another price? (Y/N): ";
		std::cin >> restart;

	} while (tolower(restart) == 'y');


	return 0;
}
