#pragma once
#include "Car.h"

class BMW : public Car
{
private:
	float fuelCapacity = 63;
	float fuelConsumtion = 17.8;
	float averageSpeed = 280;
	;
public:
	const char* getCarName();
	float getFuelCapacity();
	float getFuelConsumption();
	float getAverageSpeed(Weather weather);
};

