#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <initializer_list>
#pragma warning(disable:4996)

Sort::Sort(int size, int min, int max) {
	this->size = size;
	for (int i = 0; i < size; i++) {
		list[i] = min + (rand() % max - min + 1);
	}
}

Sort::Sort(const std::initializer_list<int>& list) {
	int i = 0;
	for (const auto& arg : list) {
		this->list[i] = arg;
		i++;
	}
	size = i;
}

Sort::Sort(int vector[], int size) {
	this->size = size;
	for (int i = 0; i < size && &vector[i] != nullptr; i++) {
		list[i] = vector[i];
	}
}

Sort::Sort(int size, ...) {
	this->size = size;
	va_list args;
	va_start(args, size);
	for (int i = 0; i < size; i++) {
		list[i] = va_arg(args, int);
	}
	va_end(args);
}

Sort::Sort(const char list[]) {
	int currentSize = 0, currentNumber = 0, decimal = 1, stringIndex = 0, listIndex = 0;
	while (list[stringIndex]) {
		if (list[stringIndex] == ',') {
			this->list[listIndex] = currentNumber;
			listIndex++;
			currentNumber = 0;
			decimal = 1;
			currentSize++;
		}
		else {
			currentNumber = currentNumber * decimal + (list[stringIndex] - '0');
			decimal *= 10;
		}
		stringIndex++;
	}
	this->list[listIndex] = currentNumber;
	size = currentSize + 1;
}

void Sort::InsertSort(bool ascendent) {
	for (int i = 1; i < size; i++)
	{
		int j = i - 1, aux = list[i];
		while (j >= 0 && list[j] > aux && ascendent)
		{
			list[j + 1] = list[j];
			j--;
		}
		while (j >= 0 && list[j] < aux && !ascendent)
		{
			list[j + 1] = list[j];
			j--;
		}
		if (list[j + 1] != aux)
			list[j + 1] = aux;
	}
}

int Sort::QuickSortPivot(int left, int right, bool ascendent) {
	int i = left - 1, p = list[right];

	for (int j = left; j < right; j++)
	{
		if (list[j] > p && !ascendent)
		{
			i++;
			std::swap(list[i], list[j]);
		}
		else if (list[j] <= p && ascendent)
		{
			i++;
			std::swap(list[i], list[j]);
		}
	}
	std::swap(list[right], list[i + 1]);
	return (i + 1);
}

void Sort::QuickSortPartition(int left, int right, bool ascendent) {
	if (left < right)
	{
		int pivotIndex = QuickSortPivot(left, right, ascendent);
		QuickSortPartition(left, pivotIndex - 1, ascendent);
		QuickSortPartition(pivotIndex + 1, right, ascendent);
	}
}

void Sort::QuickSort(bool ascendent) {
	QuickSortPartition(0, size - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent) {
	bool sorted = true;
	do {
		sorted = true;
		for (int i = 0; i < size - 1; i++)
		{
			if (list[i] > list[i + 1] && ascendent)
			{
				std::swap(list[i], list[i + 1]);
				sorted = false;
			}
			else if (list[i] < list[i + 1] && !ascendent) {
				std::swap(list[i], list[i + 1]);
				sorted = false;
			}
		}
	} while (!sorted);
}

void Sort::Print() {
	for (int i = 0; i < size; i++) {
		std::cout << list[i] << ' ';
	}
	std::cout << std::endl;
}

int Sort::GetElementsCount() {
	return size;
}

int Sort::GetElementFromIndex(int index) {
	if (index < size) {
		return list[index];
	}
}