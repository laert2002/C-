#pragma once
#include <vector>


// Time Complexity of Heap Sorting is equal O(N * logN)
class Heap
{
public:
	Heap() {}

	static void Max_Heapify(std::vector<int>&, const int&, const int& );
	static void Build_Max_Heap(std::vector<int>&);
	

	static void Min_Heapify(std::vector<int>&, const int&, const int&);
	static void Build_Min_Heap(std::vector<int>&);


	static void Heap_Sort_Asc(std::vector<int>&);
	static void Heap_Sort_Desc(std::vector<int>&);


	static inline int Parent(const int& i)  { return i / 2; }
	static inline int Left(const int& i) { return i * 2; }
	static inline int Right(const int& i) { return i * 2 + 1; }

};



void Heap::Max_Heapify(std::vector<int>& arr, const int& heap_size, const int& i)
{
	int left = Left(i);
	int right = Right(i);
	int max_index = i;

	if (left < heap_size && arr[left] > arr[i])
		max_index = left;

	if (right < heap_size && arr[right] > arr[max_index])
		max_index = right;

	if (max_index != i)
	{
		std::swap(arr[max_index], arr[i]);
		Max_Heapify(arr, heap_size, max_index);
	}
}

void Heap::Build_Max_Heap(std::vector<int>& arr)
{
	for (int i = arr.size() / 2; i >= 0; i--)
		Max_Heapify(arr, arr.size(), i);
}

void Heap::Heap_Sort_Asc(std::vector<int>& arr)
{
	Build_Max_Heap(arr);
	int heap_size = arr.size();

	for (int i = arr.size() - 1; i >= 1; i--)
	{
		std::swap(arr[0], arr[i]);
		Max_Heapify(arr, --heap_size, 0);
	}
}



void Heap::Min_Heapify(std::vector<int>& arr, const int& heap_size, const int& i)
{
	int left = Left(i);
	int right = Right(i);
	int min_index = i;

	if (left < heap_size && arr[left] < arr[i])
		min_index = left;

	if (right < heap_size && arr[right] < arr[min_index])
		min_index = right;

	if (min_index != i)
	{
		std::swap(arr[min_index], arr[i]);
		Min_Heapify(arr, heap_size, min_index);
	}
}

void Heap::Build_Min_Heap(std::vector<int>& arr)
{
	for (int i = arr.size() / 2; i >= 0; i--)
		Min_Heapify(arr, arr.size(), i);
}

void Heap::Heap_Sort_Desc(std::vector<int>& arr)
{
	Build_Min_Heap(arr);
	int heap_size = arr.size();


	for (int i = arr.size() - 1; i >= 1; i--)
	{
		std::swap(arr[0], arr[i]);
		Min_Heapify(arr, --heap_size, 0);
	}
}