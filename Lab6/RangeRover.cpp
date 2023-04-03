#include "RangeRover.h"

const char* RangeRover::getCarName() {
	return "Range Rover";
}

float RangeRover::getFuelCapacity() {
	return fuelCapacity;
}

float RangeRover::getFuelConsumption() {
	return fuelConsumtion;
}

float RangeRover::getAverageSpeed(Weather weather) {
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