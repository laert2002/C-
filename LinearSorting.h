#pragma once
#include <vector>

class LinearSorting
{
public:
	// Time complexity O(n + K) it's useful when K == O(N) from range [0 to K]
	static void CountingSort(std::vector<int>&, std::vector<int>&, const int&);

	static void RadixSort(std::vector<int>&, const int&);
	static void CountSort_Radix(std::vector<int>&, const int&);
};


void LinearSorting::CountingSort(std::vector<int>& arr, std::vector<int>& sorted, const int& K)
{
	std::vector<int> Count(K + 1, 0);

	for (const int& val : arr)
		++Count[val];

	for (int i = 1; i <= K; i++)
		Count[i] += Count[i - 1];

	for (int i = arr.size() - 1; i >= 0; i--)
		sorted[ Count[ arr[i] ] - 1 ] = arr[i], --Count[arr[i]];
}



void LinearSorting::RadixSort(std::vector<int>& arr, const int& d)
{
	int pow_10 = 1;
	for (int i = 1; i <= d; i++, pow_10 *= 10)
		CountSort_Radix(arr, pow_10);
}


void LinearSorting::CountSort_Radix(std::vector<int>& arr, const int& k)
{	
	std::vector<int> Count(10, 0);
	std::vector<int> sorted(arr.size());

	for (const int& val : arr)
		++Count[(val / k) % 10];

	for (int i = 1; i < 10; i++)
		Count[i] += Count[i - 1];

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		const int val = arr[i];
		sorted[Count[(val / k) % 10] - 1] = val, --Count[(val / k) % 10];
	}

	arr = sorted;
}

