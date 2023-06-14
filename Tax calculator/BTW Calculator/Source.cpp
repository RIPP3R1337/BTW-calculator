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
#endif // _WIN32


		double prijs;
		char omrekenen;

		std::cout << "Wilt u inclusief of exclusief berekenen? (I/E): ";
		std::cin >> omrekenen;
		// convert to lowercase, and then convert back to a char type (as the tolower() function returns an integer)
		omrekenen = char(tolower(omrekenen));
		// check that the user entered i or e
		if (omrekenen != 'i' && omrekenen != 'e') {
			std::cout << "Voer alstublieft I/E in. U voerde in: " << omrekenen << "." << std::endl;
			continue;  // restart the loop if input is invalid
		}

		std::cout << "Voer uw bedrag in: ";
		std::cin >> prijs;
		// check if prijs is a valid positive number
		if (!isPositiveDouble(prijs)) {
			std::cout << "Voer alstublieft een positief nummer in. U antwoordde: " << prijs << "." << std::endl;
		}

#ifdef _WIN32
		system("cls");
#else // ie Linux or MacOS
		system("clear");
#endif

		switch (omrekenen)
		{ // since we converted omrekenen to be lowercase no matter what, we don't need a separate case for 'e' and 'E', etc
		case 'e':
			std::cout << "U heeft " << prijs << " Euro ingevoerd\n\n";
			std::cout << "21% BTW = +" << roundToTwoDecimalPlaces(prijs * 21 / 100) << " Euro\n\n";
			std::cout << "Dit bedrag is: " << roundToTwoDecimalPlaces(prijs * 1.21) << " Euro inclusief BTW\n\n";
			break;
		case 'i':
			std::cout << "U heeft " << prijs << " Euro ingevoerd\n\n";
			std::cout << "21% BTW = -" << roundToTwoDecimalPlaces(prijs * 21 / 121) << " Euro\n\n";
			std::cout << "Dit bedrag is: " << roundToTwoDecimalPlaces(prijs / 1.21) << " Euro Exclusief BTW\n\n";
			break;
		default:
			std::cout << "[ERROR] Geen geldige prijs of er is een ander fout opgetreden!\n";
			
		}


		std::cout << "\n\nWilt u een nieuw bedrag berekenen? (y/n): ";
		std::cin >> restart;

	} while (restart == 'Y' || restart == 'y');


	return 0;
}
