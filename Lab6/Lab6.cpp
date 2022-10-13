#include "Lab6.h"

namespace lab6
{
	void bubbleSort(std::vector<int>&);
	void quickSort(std::vector<int>&);

	int Sum(const std::vector<int>& v)
	{
		int sum = 0;
		for (size_t i = 0; i < v.size(); i++)
		{
			sum += v[i];
		}

		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return INT32_MAX;
		}

		int min = v[0];
		for (size_t i = 1; i < v.size(); i++)
		{
			if (v[i] < min)
			{
				min = v[i];
			}
		}

		return min;
	}

	int Max(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return INT32_MIN;
		}

		int max = v[0];
		for (size_t i = 1; i < v.size(); i++)
		{
			if (v[i] > max)
			{
				max = v[i];
			}
		}

		return max;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0.f;
		}

		float sum = 0.f;

		for (size_t i = 0; i < v.size(); i++)
		{
			sum += v[i];
		}

		return sum / v.size();
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}

		size_t maxIndex = 0;
		size_t maxCount = 0;
		size_t count = 0;

		for (size_t i = 0; i < v.size(); i++)
		{
			int compare = v[i];

			for (size_t j = 0; j < v.size(); j++)
			{
				if (v[j] == compare)
				{
					++count;
				}
			}

			if (count > maxCount)
			{
				maxCount = count;
				maxIndex = i;
			}

			count = 0;
		}

		return v[maxIndex];
	}

	void SortDescending(std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return;
		}
		
		//bubbleSort(v);
		quickSort(v);
	}

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

		for (size_t i = left; i < r; i++)
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


}