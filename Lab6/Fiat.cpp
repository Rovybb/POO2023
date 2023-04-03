#include "Fiat.h"

const char* Fiat::getCarName() {
	return "Fiat";
}

float Fiat::getFuelCapacity() {
	return fuelCapacity;
}

float Fiat::getFuelConsumption() {
	return fuelConsumtion;
}

float Fiat::getAverageSpeed(Weather weather) {
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