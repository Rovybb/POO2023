#pragma once
#include "Car.h"

class Volvo : public Car
{
private:
	float fuelCapacity = 54;
	float fuelConsumtion = 6.2;
	float averageSpeed = 180;
public:
	const char* getCarName();
	float getFuelCapacity();
	float getFuelConsumption();
	float getAverageSpeed(Weather weather);
	~Volvo() {}
};

