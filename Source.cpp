#include "round.h"
#include "positive.h"
#include "includes.h"
#include "ignoreLine.h"

// Function to clear the console screen based on the operating system
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to set the standard output format for monetary values
void setOutputFormat() {
    std::cout.precision(2);
    std::cout << std::fixed;
}

int main() {
    const double TAX_RATE = 21.0;

    // Set the locale to the system's default
    std::locale myLocale("");
    std::cout.imbue(myLocale);

    char restart;

    do {
        clearScreen();

        std::string price; // To allow user input with commas
        double prijs = 0.0;
        char omrekenen;

        // Loop to ensure the user enters either 'I' or 'E'
        while (true) {
            std::cout << "Would you like to include or exclude tax? (I/E): ";
            std::cin >> omrekenen;
            omrekenen = char(tolower(omrekenen)); // Convert to lowercase

            if (omrekenen == 'i' || omrekenen == 'e') {
                break;
            }
            else {
                std::cout << "Please enter I/E. You entered: " << omrekenen << "." << std::endl;
                ignoreLine();
                std::cout << "\nPress any key to return to the previous section." << std::endl;
                _getch();
                clearScreen();
            }
        }

        // Input and validation loop
        while (true) {
            std::cout << "Enter your amount: ";
            std::cin >> price;

            // Replace comma with a period for correct conversion
            std::replace(price.begin(), price.end(), ',', '.');

            std::istringstream iss(price);
            if (iss >> prijs && isPositiveDouble(prijs)) {
                break;  // Valid input
            }
            else {
                std::cout << "Please enter a valid positive number. You entered: " << price << "." << std::endl;
                ignoreLine();
                std::cout << "\nPress any key to try again." << std::endl;
                _getch();
                clearScreen();
            }
        }

        clearScreen();
        setOutputFormat();

        switch (omrekenen) {
        case 'e':
            std::cout << "You entered " << prijs << " Euro\n\n";
            std::cout << "21% TAX = +" << roundToTwoDecimalPlaces(prijs * TAX_RATE / 100) << " Euro\n\n";
            std::cout << "This amount is: " << roundToTwoDecimalPlaces(prijs * 1.21) << " Euro including TAX\n\n";
            break;
        case 'i':
            std::cout << "You entered " << prijs << " Euro\n\n";
            std::cout << "21% TAX = -" << roundToTwoDecimalPlaces(prijs * TAX_RATE / 121) << " Euro\n\n";
            std::cout << "This amount is: " << roundToTwoDecimalPlaces(prijs / 1.21) << " Euro excluding TAX\n\n";
            break;
        default:
            std::cout << "[ERROR] An unexpected error has occurred!\n";
            break;
        }

        std::cout << "\n\nWould you like to calculate another price? (Y/N): ";
        std::cin >> restart;
        ignoreLine();

    } while (tolower(restart) == 'y');

    clearScreen();
    std::cout << "\n\n#### Exiting...####\n\n";
    system("pause");

    return 0;
}
