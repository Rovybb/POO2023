#pragma once
#include "Car.h"

class RangeRover : public Car
{
private:
	float fuelCapacity = 82;
	float fuelConsumtion = 7.6;
	float averageSpeed = 250;
public:
	const char* getCarName();
	float getFuelCapacity();
	float getFuelConsumption();
	float getAverageSpeed(Weather weather);
	~RangeRover() {}
};

