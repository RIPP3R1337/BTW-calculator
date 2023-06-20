#include "round.h"
#include "positive.h"
#include "includes.h"
#include "ignoreLine.h"


int main()
{
	/*
	This code writes a floating point number using the global locale given by the environment
	For example, in a system configured with a Spanish locale as default, 
	this could write the number using a comma decimal separator:
	*/

	std::locale myLocale("");
	std::cout.imbue(myLocale);

	char restart;

	do {
#ifdef _WIN32
		system("cls");
#else
		system("clear"); // ie Linux or MacOS
#endif 


		std::string price; // this is so we can let the user input a comma
		double prijs;
		char omrekenen;

		// while loop to loop back if user mistakenly enters anything else besides I or E
		while (true) {
			std::cout << "Would you like to include or exclude tax? (I/E): ";
			std::cin >> omrekenen;
			// convert to lowercase, and then convert back to a char type (as the tolower() function returns an integer)
			omrekenen = char(tolower(omrekenen));
			// check that the user entered i or e
			if (omrekenen == 'i' || omrekenen == 'e') {
				break;  // Valid input, exit the loop
			}
			else {
				std::cout << "Please enter I/E. You entered: " << omrekenen << "." << std::endl;
				ignoreLine();
				std::cout << "\nPress any key to return to previous section" << "." << std::endl;
				_getch(); // gets user their key input

#ifdef _WIN32
				system("cls");
#else
				system("clear");
#endif

			}
		}

		std::cout << "Enter your amount: ";
		std::cin >> price;
		// We convert the string back to double and replace the user inputted comma with a period
		std::replace(price.begin(), price.end(), ',', '.');
		std::istringstream iss(price);
		if (!(iss >> prijs)) {
			std::cout << "Please enter a valid number, you entered: " << price << "." << std::endl;
		}
		
		// check if prijs is a valid positive number
		if (!isPositiveDouble(prijs)) {
			std::cout << "Please enter a positive number. You entered: " << prijs << "." << std::endl;
			system("pause");
			exit(0);
		}


#ifdef _WIN32
		system("cls");
#else // ie Linux or MacOS
		system("clear");
#endif
		
		
		switch (omrekenen)
		{ // since we converted omrekenen to be lowercase no matter what, we don't need a separate case for 'e' and 'E', etc
		case 'e':
			std::cout.precision(2);
			std::cout << std::fixed << "You entered " << prijs << " Euro\n\n";
			std::cout << "21% TAX = +" << roundToTwoDecimalPlaces(prijs * 21 / 100) << " Euro\n\n";
			std::cout << "This amount is: " << roundToTwoDecimalPlaces(prijs * 1.21) << " Euro including TAX\n\n";
			break;
		case 'i':
			std::cout.precision(2);
			std::cout << std::fixed <<"You entered " << prijs << " Euro\n\n";
			std::cout << "21% TAX = -" << roundToTwoDecimalPlaces(prijs * 21 / 121) << " Euro\n\n";
			std::cout << "This amount is: " << roundToTwoDecimalPlaces(prijs / 1.21) << " Euro excluding TAX\n\n";
			break;
		default:
			std::cout << "[ERROR] Not a valid value or another error has occured!\n";
			
		}

			
		std::cout << "\n\nWould you like to calculate another price? (Y/N): ";
		std::cin >> restart;
		ignoreLine();

	} while (tolower(restart) == 'y');




	return 0;
}
