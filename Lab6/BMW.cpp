#include "BMW.h"

const char* BMW::getCarName() {
	return "BMW";
}

float BMW::getFuelCapacity() {
	return fuelCapacity;
}

float BMW::getFuelConsumption() {
	return fuelConsumtion;
}

float BMW::getAverageSpeed(Weather weather) {
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