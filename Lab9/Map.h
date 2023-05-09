#pragma once
#include <iostream>

template <typename K, typename V>

class Map
{
	struct Pair {
		K key;
		V value;
		int index;
	};
	Pair* pairs;
	int indexCurent;
	int maxElements;

	struct MapEntry {
		K key;
		V value;
		int index;

		MapEntry(K k, V v, int i) : key(k), value(v), index(i) {}
	};

	class MyIterator {
	public:
		Pair* pairs;
		MyIterator& operator++() { pairs++; return *this; }
		bool operator != (const MyIterator& m) { return pairs != m.pairs; }
		MapEntry operator* () { return MapEntry(pairs->key, pairs->value, pairs->index); }
	};

public:

	Map()
	{
		this->maxElements = 10;
		this->pairs = new Pair[this->maxElements];
		this->indexCurent = 0;
	}

	MyIterator begin() { MyIterator tmp; tmp.pairs = &pairs[0]; return tmp; }
	MyIterator end() { MyIterator tmp; tmp.pairs = &pairs[indexCurent]; return tmp; }

	V& operator[](const K& key)
	{
		for (int i = 0; i < indexCurent; i++)
			if (pairs[i].key == key)
				return pairs[i].value;

		pairs[indexCurent] = { key, V{}, indexCurent };
		indexCurent++;
		return pairs[indexCurent - 1].value;
	}

	void Set(K key, V value)
	{	
		int ok = 0;
		for (int i = 0; i < indexCurent; i++)
			if (pairs[i].key == key)
			{
				pairs[i].value = value;
				ok = 1;
			}
		if (ok == 0)
		{
			pairs[indexCurent] = { key,value,indexCurent };
			indexCurent++;
		}	
	}

	bool Get(const K& key, V& value)
	{
		for (int i = 0; i < indexCurent; i++)
			if (pairs[i].key == key)
			{
				value = pairs[i].value;
				return true;
			}
		return false;
	}

	int Count()
	{	
		return indexCurent;
	}

	void Clear()
	{
		delete[] pairs;
		maxElements = 10;
		pairs = new Pair[maxElements];
		indexCurent = 0;
	}

	bool Delete(const K& key)
	{
		int removeIndex = -1;
		for (int i = 0; i < indexCurent; i++)
			if (pairs[i].key == key)
			{
				removeIndex = i;
				break;
			}
		if (removeIndex >= 0)
		{
			for (int i = removeIndex; i < indexCurent - 1; i++)
				pairs[i] = pairs[i + 1];
			indexCurent--;
			return true;
		}
		return false;
	}

	bool Includes(const Map<K, V>& map)
	{
		for (auto it = map.begin(); it != map.end(); it++) {
			V value;
			if (!Get(it->key, value) || value != it->value) {
				return false;
			}
		}
		return true;
	}

};