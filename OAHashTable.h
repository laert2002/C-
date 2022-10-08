#pragma once
#include <vector>

class OAHashing
{
public:
	OAHashing(const unsigned& TS, const unsigned& c1 = 1, const unsigned& c2 = 1) :TableSize(TS), HashTable( TableSize, std::make_pair(0, 0) ), C1(c1), C2(c2) {}

	bool Insert(const unsigned&);

	int Search(const unsigned&) const;

	bool SearchHash(const unsigned& key) const { return Search(key) == -1 ? false : true; }

	bool Delete(const unsigned&);
private:
	inline unsigned AuxHashFunction(const unsigned& key) const { return  (key * (key + 3)) % TableSize; }

	inline unsigned LinearHashFunction(const unsigned& key, const unsigned& i) const { return (AuxHashFunction(key) + i) % TableSize; }

	inline unsigned QuadraticHashFunciton(const unsigned& key, const unsigned& i) const { return (AuxHashFunction(key) + C1 * i + C2 * i * i) % TableSize; }

	inline unsigned H1(const unsigned& key) const { return key % TableSize; }
	inline unsigned H2(const unsigned& key) const { return 1 + key % (TableSize - 1); }
	inline unsigned DoubleHashing(const unsigned& key, const int& i) const { return (H1(key) + i * H2(key)) % TableSize; } // Table size should be prime number for better hashing


	const unsigned TableSize;
	std::vector <std::pair<unsigned, int>> HashTable; // second value - 0 means empty, 1 means inserted, -1 means deleted

	unsigned C1, C2; // THis for Quadratic Hashing
};

bool OAHashing::Insert(const unsigned& key)
{
	if (Search(key) != -1)
		return false;

	unsigned step = 0, index;
	do
	{
		index = LinearHashFunction(key, step);

		if (HashTable[index].second != 1)
		{
			HashTable[index] = std::make_pair(key, 1);
			return true;
		}


	} while (++step != TableSize);

	return false;
}

int OAHashing::Search(const unsigned& key) const
{

	unsigned step = 0, index;

	do
	{
		index = LinearHashFunction(key, step);

		if (HashTable[index].second == 0)
			return -1;
		if (HashTable[index] == std::make_pair(key, 1))
			return index;

	} while (++step != TableSize);

	return -1;
}

bool OAHashing::Delete(const unsigned& key)
{
	int index = Search(key);
	if (index != -1)
	{
		HashTable[index].second = -1;
		return true;
	}
	return false;
}
