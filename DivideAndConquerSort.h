#pragma once
#include <vector>
#include <ctime>

class DivideAndConquer
{
public:
	static void MergeSort(std::vector<int>&, const int&, const int&);
	static void Merge(std::vector<int>&, const int&, const int&, const int&);

	
	static void QuickSort(std::vector<int>&, const int&, const int&);
	static int Partition(std::vector<int>&, const int&, const int&);
	static int RandomizedPartition(std::vector<int>&, const int&, const int&);
};

void DivideAndConquer::MergeSort(std::vector<int>&arr, const int& left, const int& right)
{
	if (left >= right)
		return;

	int mid = left - (left - right) / 2; // same (left + right) / 2;

	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);
	
	Merge(arr, left, mid, right);
}


void DivideAndConquer::Merge(std::vector<int>& arr, const int& left, const int& mid, const int& right)
{
	std::vector<int> sorted(right - left + 1);
	int left_index = left;
	int right_index = mid + 1;
	int index = 0;

	while (left_index <= mid && right_index <= right)
	{
		if (arr[left_index] < arr[right_index])
			sorted[index++] = arr[left_index++];

		else
			sorted[index++] = arr[right_index++];
	}


	while (left_index <= mid)
		sorted[index++] = arr[left_index++];
	while (right_index <= right)
		sorted[index++] = arr[right_index++];


	for (index = 0; index < right - left + 1; index++)
		arr[index + left] = sorted[index];
}




void DivideAndConquer::QuickSort(std::vector<int>& arr, const int& left, const int& right)
{
	if (left >= right)
		return;

	int partition = Partition(arr, left, right);

	QuickSort(arr, left, partition - 1);
	QuickSort(arr, partition + 1, right);
}

int DivideAndConquer::Partition(std::vector<int>& arr, const int& left, const int& right)
{
	const int& pivot = arr[right];
	int index = left - 1;

	for (int i = left; i < right; i++)
	{
		if (arr[i] <= pivot)
			std::swap(arr[++index], arr[i]);
	}

	std::swap(arr[++index], arr[right]);
	return index;
}

int DivideAndConquer::RandomizedPartition(std::vector<int>& arr, const int& left, const int& right)
{
	srand( time(NULL) );
	int random_index = rand() % (right - left + 1) + left;
	std::swap(arr[right], arr[random_index]);

	return Partition(arr, left, right);
}
