#pragma once
#include <iostream>
#include <string>

bool isPositiveDouble(double x) {
	// check if it's positive
	if (x < 0) {
		return false;
	}

	// convert to string for checking if it's a valid number
	std::string str = std::to_string(x);
	// check each character of the string to see if it's a digit or "."
	for (char c : str) {
		if (std::isdigit(c)) {
			continue;
		}
		else if (c == '.') {
			continue;
		}
		else {
			return false;
		}
	}

	// if none of the above checks triggered a 'return false', then we can go ahead and return true
	return true;
}

