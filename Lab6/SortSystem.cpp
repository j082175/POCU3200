#include "SortSystem.h"

void bubbleSort(std::vector<int>& v)
{
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		for (size_t j = 0; j < v.size() - 1 - i; j++)
		{
			if (v[j] < v[j + 1])
			{
				std::swap(v[j], v[j + 1]);
			}
		}
	}
}

int partition(std::vector<int>& v, int l, int r)
{
	int pivot = v[r];

	int left = l;

	for (int i = left; i < r; i++)
	{
		if (v[i] > pivot)
		{
			std::swap(v[i], v[left]);
			++left;
		}
	}

	std::swap(v[left], v[r]);

	return left;
}

void binarySearchRecursive(std::vector<int>& v, int l, int r)
{
	if (l >= r)
	{
		return;
	}

	int pivot = partition(v, l, r);

	binarySearchRecursive(v, l, pivot - 1);
	binarySearchRecursive(v, pivot + 1, r);
}

void quickSort(std::vector<int>& v)
{
	binarySearchRecursive(v, 0, v.size() - 1);
}