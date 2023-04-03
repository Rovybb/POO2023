#pragma once

enum class Weather { Rain, Sunny, Snow };

class Car
{
public:
	virtual const char* getCarName() = 0;
	virtual float getFuelCapacity() = 0;
	virtual float getFuelConsumption() = 0;
	virtual float getAverageSpeed(Weather wheather) = 0;
};