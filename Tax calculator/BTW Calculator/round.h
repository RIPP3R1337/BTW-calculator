#pragma once
#include <iostream>

// function which rounds a float to two decimal places
float roundToTwoDecimalPlaces(float value) {
	return std::round(value * 100) / 100;
}

