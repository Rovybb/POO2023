#include "Circuit.h"
#include <iostream>

Circuit::~Circuit() {
	for (int i = 0; i < index; i++)
	{
		delete cars[i];
	}
	delete[] cars;
}

void Circuit::SetLength(float length) {
	this->length = length;
}

void Circuit::SetWeather(Weather weather) {
	this->weather = weather;
}

void Circuit::AddCar(Car* car) {
	if (index == 0) {
		cars = (Car**)malloc((index + 1) * sizeof(Car*));
	}
	else {
		cars = (Car**)realloc(cars, (index + 1) * sizeof(Car *));
	}
	cars[index++] = car;
}

void Circuit::Race() {
	bool ok = false;
	while (!ok) {
		ok = true;
		for (int i = 0; i < index - 1; i++) {
			if (length / cars[i]->getAverageSpeed(weather) > length / cars[i + 1]->getAverageSpeed(weather)) {
				std::swap(cars[i], cars[i + 1]);
				ok = false;
			}
		}
	}
}

void Circuit::ShowFinalRanks() {
	int place = 1;
	for (int i = 0; i < index; i++) {
		if (cars[i]->getFuelConsumption() * length >= cars[i]->getFuelCapacity()) {
			std::cout << "Place " << place << ": " << cars[i]->getCarName() << std::endl;
			place++;
		}
	}
}


void Circuit::ShowWhoDidNotFinish() {
	for (int i = 0; i < index; i++) {
		if (cars[i]->getFuelConsumption() * length < cars[i]->getFuelCapacity()) {
			std::cout << cars[i]->getCarName() << " did not finish" << std::endl;
		}
	}
}