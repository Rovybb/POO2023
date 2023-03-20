#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
	Sort list1(10, 6, 80);

	Sort list2({ 45, 54, 2, 109, 3, 23 });

	int array[] = { 55, 48, 98, 74, 5, 986 };
	Sort list3(array, 6);

	Sort list4(7, 23, 3, 54, 6, 90, 5, 345);

	Sort list5("54,2,43,66,4,6,7,50");

	list1.Print();
	list2.Print();
	list3.Print();
	list4.Print();
	list5.Print();

	list1.BubbleSort();
	list2.InsertSort(false);
	list3.QuickSort(true);
	list4.BubbleSort();
	list5.InsertSort(true);

	list1.Print();
	list2.Print();
	list3.Print();
	list4.Print();
	list5.Print();


	return 0;
}