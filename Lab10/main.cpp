#include "Array.h"

int main()
{

	Array<int> v = 10;
	v += 11;
	v += 1;
	v += 2;
	v += 3;



	Array<int> c = 5;

	c += 400;
	c += 12;
	c += 1100;
	c += 100;
	c += 12231;


	v.Insert(3, c);
	v.Insert(1, 10);
	v.Delete(1);

	v = c;

	v.Print();

	v.Sort();
	v.Sort(v.compare);
	Compare* comparator = new CompareC<int>;
	v.Sort(comparator);


	cout << v.BinarySearch(100) << endl;
	cout << v.BinarySearch(12231, v.compare) << endl;
	cout << v.BinarySearch(14, comparator) << endl;

	cout << v.Find(100) << endl;
	cout << v.Find(12231, v.compare) << endl;
	cout << v.Find(1100, comparator) << endl;
	
	for (auto it : v)
	{
		cout << *it << ' ';
	}
	
	v.Print();

}