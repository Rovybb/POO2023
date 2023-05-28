#pragma once
#include <iostream>
#include <exception>
#include <utility>
#include <algorithm>
using namespace std;

class exception1 : public exception
{
	virtual const char* what() const throw()
	{
		return "Index is out of range!";
	}
};

class exception2 : public exception
{
	virtual const char* what() const throw()
	{
		return "Index is invalid!";
	}
};

class exception3 : public exception
{
	virtual const char* what() const throw()
	{
		return "Capacity is maximum. Can't add more!";
	}
};

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class CompareC : public Compare
{
public:

	int CompareElements(void* e1, void* e2) override
	{
		T* left = static_cast<T*>(e1);
		T* right = static_cast<T*>(e2);
		if (*left > *right)
			return 1;
		if (*left == *right)
			return 2;
		return 0;
	}
};

template<class T>
class ArrayIterator
{
private:

	int Current; // mai adaugati si alte date si functii necesare pentru iterator
	T** p;

public:

	ArrayIterator(T** list, int index)
	{
		Current = index;
		p = list;
	}

	ArrayIterator& operator ++ ()
	{
		Current++;
		return *this;
	}

	ArrayIterator& operator -- ()
	{
		Current--;
		return *this;
	}

	bool operator==(ArrayIterator<T>& other)
	{
		return p[Current] == other.p[other.Current];
	}

	bool operator!=(ArrayIterator<T>& other)
	{
		return p[Current] != other.p[other.Current];
	}

	T* operator*()
	{
		return p[Current];
	}

	T* GetElement()
	{
		return p[Current];
	}
};

template<class T>
class Array
{
private:

	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista



public:

	static int compare(const T& v1, const T& v2)
	{
		if (v1 > v2)
			return 1;
		if (v1 == v2)
			return 2;
		return 0;
	}

	Array() // Lista nu e alocata, Capacity si Size = 0
	{
		this->Capacity = 0;
		this->Size = 0;
		this->List = nullptr;
	}

	~Array()
	{
		for (int i = 0; i < Size; i++)
			delete List[i];
		delete[]List;
	}

	Array(int capacity)  // Lista e alocata cu 'capacity' elemente
	{
		this->List = new T * [capacity];
		this->Capacity = capacity;
		this->Size = 0;
	}

	Array(const Array<T>& otherArray) // constructor de copiere
	{
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		List = new T * [Capacity];

		for (int i = 0; i < Size; i++)
			List[i] = new T(*otherArray.List[i]);
	}


	T& operator[] (int index) // arunca exceptie daca index este out of range
	{
		exception1 index_out_of_range;

		try
		{
			if (index < 0 || index >= this->Size)
				throw index_out_of_range;

			return *(this->List[index]);
		}

		catch (exception& e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}
	}


	const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
	{
		exception3 capacity_reached;
		try
		{

			if (this->Size == this->Capacity)
			{
				throw capacity_reached;

			}

			this->List[this->Size] = new T(newElem);
			this->Size++;

			return *(this);
		}
		catch (exception& e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}
	}

	const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
		exception2 index_invalid;
		try
		{
			if (index < 0 || index >= this->Size)
				throw index_invalid;

			List[index] = new T(newElem);
			return *(this);
		}

		catch (exception& e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}
	}

	const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
		exception2 index_invalid;
		try
		{
			if (index + otherArray.Size > Capacity)
				throw index_invalid;

			for (int i = 0; i < otherArray.Size; i++)
				List[index + i] = new T(*otherArray.List[i]);

			Size = index + otherArray.Size;
			return *(this);
		}

		catch (exception& e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}
	}

	const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	{
		exception2 index_invalid;
		try
		{
			if (index < 0 || index >= Size)
				throw index_invalid;

			for (int i = index; i < Size - 1; i++)
				if (index == Size - 1)
					List[i] = nullptr;
				else
				{

					List[i] = new T(*List[i + 1]);

				}
			List[Size - 1] = nullptr;
			Size--;
		}

		catch (exception& e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}
	}


	bool operator=(const Array<T>& otherArray)
	{
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		List = new T * [Capacity];

		for (int i = 0; i < Size; i++)
			List[i] = new T(*otherArray.List[i]);
		return true;
	}


	void Sort() // sorteaza folosind comparatia intre elementele din T
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (*List[i] > *List[j])
					swap(*List[i], *List[j]);
	}

	void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (compare(*List[i], *List[j]) == 1)
					swap(*List[i], *List[j]);
	}

	void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
	{

		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (comparator->CompareElements(List[i], List[j]) == 1)
					swap(*List[i], *List[j]);

	}


	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
	{
		int st = 0;
		int dr = Size - 1;
		int poz = 0;

		while (st <= dr && poz == 0)
		{
			int m = (st + dr) / 2;
			if (*List[m] == elem)
				return m;
			else
			{
				if (*List[m] < elem)
					st = m + 1;
				else
					dr = m - 1;
			}
		}

		if (poz != 0)
			return poz;
		else
			return -1;

	}

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
	{
		int st = 0;
		int dr = Size - 1;
		int poz = 0;

		while (st <= dr && poz == 0)
		{
			int m = (st + dr) / 2;
			if (compare(*List[m], elem) == 2)
				return m;
			else
			{
				if (compare(*List[m], elem) == 0)
					st = m + 1;
				else
					dr = m - 1;
			}
		}

		if (poz != 0)
			return poz;
		else
			return -1;
	}

	int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
	{
		int st = 0;
		int dr = Size - 1;
		int poz = 0;

		while (st <= dr && poz == 0)
		{
			int m = (st + dr) / 2;
			if (comparator->CompareElements(List[m], const_cast<T*>(&elem)) == 2)
				return m;
			else
			{
				if (comparator->CompareElements(List[m], const_cast<T*>(&elem)) == 0)
					st = m + 1;
				else
					dr = m - 1;
			}
		}

		if (poz != 0)
			return poz;
		else
			return -1;
	}


	int Find(const T& elem) // cauta un element in Array
	{
		for (int i = 0; i < Size; i++)
			if (*List[i] == elem)
				return i;
		return -1;

	}

	int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
	{
		for (int i = 0; i < Size; i++)
			if (compare(*List[i], elem))
				return i;
		return -1;
	}

	int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
	{
		for (int i = 0; i < Size; i++)
			if (comparator->CompareElements(List[i], const_cast<T*>(&elem)) == 2)
				return i;
		return -1;
	}


	int GetSize()
	{
		return this->Size;
	}

	int GetCapacity()
	{
		return this->Capacity;
	}

	void Print()
	{
		for (int i = 0; i < Size; i++)
			cout << *List[i] << ' ';
		cout << endl;
	}

	ArrayIterator<T> begin()
	{
		return ArrayIterator<T>(List, 0);
	}

	ArrayIterator<T> end()
	{
		return ArrayIterator<T>(List, Size);
	}


};