#pragma once
#include "Car.h"

class Circuit
{
private:
	float length;
	int index = 0;
	Weather weather;
	Car** cars;
	
public:
	~Circuit();
	void SetLength(float);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

