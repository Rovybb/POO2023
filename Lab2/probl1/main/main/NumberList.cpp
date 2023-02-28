#include "NumberList.h"
#include <iostream>

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (this->count >= 10)
		return false;
	else
	{
		this->numbers[this->count] = x;
		this->count++;
		return true;
	}
}

void NumberList::Sort()
{
    bool ok = true;
    do {
        ok = true;
        for (int i = 0; i < this->count - 1; i++)
        {
            if (this->numbers[i] < this->numbers[i + 1])
            {
                std::swap(this->numbers[i], this->numbers[i + 1]);
                ok = false;
            }
        }

    } while (!ok);
}

void NumberList::Print()
{
    std::cout << "Your list of numbers: ";
    for (int i = 0; i < this->count; i++)
        std::cout << this->numbers[i] << ' ';
}