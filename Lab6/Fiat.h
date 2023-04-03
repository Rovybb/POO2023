#pragma once
#include "Car.h"

class Fiat :  public Car
{
private:
	float fuelCapacity = 45;
	float fuelConsumtion = 6.6;
	float averageSpeed = 231;
public:
	const char* getCarName();
	float getFuelCapacity();
	float getFuelConsumption();
	float getAverageSpeed(Weather weather);
	~Fiat() {}
};

