#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
	NumberList numberList;
	int input;
	bool running = true;
	numberList.Init();
	while (running) {
		cout << endl;
		cout << "0 - Close app" << endl;
		cout << "1 - Add a number to the list" << endl;
		cout << "2 - Sort the list" << endl;
		cout << "3 - Print the list" << endl;
		cout << "Enter instruction: ";
		cin >> input;
		cout << endl;
		if (!(input >= 0 && input <= 3))
		{
			cout << "Error: Invalid instrution. Enter instruction: ";
			cin >> input;
			cout << endl;
		}
		switch (input)
		{
		case 0:
			cout << "The app has stopped" << endl;
			running = false;
			break;
		case 1:
			cout << "Input number: ";
			int x;
			cin >> x;
			if (numberList.Add(x))
			{
				cout << "Item added";
			}
			else
			{
				cout << "Error: Too many items!";
			}
			break;
		case 2:
			numberList.Sort();
			cout << "List sorted";
			break;
		case 3:
			numberList.Print();
			cout << endl;
			break;
		default:
			break;
		}
	}
	
    return 0;
}
