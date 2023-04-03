#include "Seat.h"

const char* Seat::getCarName() {
	return "Seat";
}

float Seat::getFuelCapacity() {
	return fuelCapacity;
}

float Seat::getFuelConsumption() {
	return fuelConsumtion;
}

float Seat::getAverageSpeed(Weather weather) {
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