#include "Volvo.h"

const char* Volvo::getCarName() {
	return "Volvo";
}

float Volvo::getFuelCapacity() {
	return fuelCapacity;
}

float Volvo::getFuelConsumption() {
	return fuelConsumtion;
}

float Volvo::getAverageSpeed(Weather weather) {
	switch (weather)
	{
	case Weather::Rain:
		return averageSpeed * 0.5;
		break;
	case Weather::Sunny:
		return averageSpeed * 0.75;
		break;
	case Weather::Snow:
		return averageSpeed;
		break;
	default:
		break;
	}
}