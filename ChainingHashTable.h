#pragma once
#include <list>
#include <algorithm>


class ChainingHashing
{
public:
	ChainingHashing(const unsigned& size, const unsigned& coef, const unsigned& Pr) :C(coef), 
																					TableSize(size), 
																					HashTable(new std::list<unsigned>[TableSize]),
																					P(Pr)
	{
	}

	~ChainingHashing() { delete[] HashTable; }

	bool Insert(const unsigned&);

	bool Delete(const unsigned&);
	
	bool Search(const unsigned&) const ;

private:
	unsigned HashFunction1(const unsigned& key) const { return key % TableSize; }

	unsigned HashFunction2(const unsigned& key) const { return  (C * key) & TableSize; }

	//unsigned UniversalHashing(const unsigned& key, const unsigned& a, const unsigned& b) const
	//{
		// a should be in 1 to p - 1 interval 
		// b should be in 0 to p - 1 interval

		//return ((a * key + b) % P) % TableSize;

	//}



	const unsigned C;
	const unsigned TableSize;
	std::list<unsigned>* HashTable;

	//const unsigned P; // This is for universal hashing P should be PRIME and Bigger than expected key value
};

bool ChainingHashing::Insert(const unsigned& key)
{
	if (Search(key) == false)
	{
		HashTable[HashFunction1(key)].push_back(key);
		return true;
	}

	return false;
}

bool ChainingHashing::Delete(const unsigned& key)
{
	if (Search(key))
	{
		std::list<unsigned>& lst = HashTable[HashFunction1(key)];
		std::list<unsigned>::iterator fnd = std::find(lst.begin(), lst.end(), key);

		lst.erase(fnd);

		return true;
	}

	return false;
}


bool ChainingHashing::Search(const unsigned& key) const
{
	std::list<unsigned>& lst = HashTable[HashFunction1(key)];

	return std::find(lst.begin(), lst.end(), key) != lst.end();
}


