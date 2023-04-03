#pragma once
#include "Car.h"

class Seat : public Car
{
private:
	float fuelCapacity = 55;
	float fuelConsumtion = 9.3;
	float averageSpeed = 254;
public:
	const char* getCarName();
	float getFuelCapacity();
	float getFuelConsumption();
	float getAverageSpeed(Weather weather);
	~Seat() {}
};

