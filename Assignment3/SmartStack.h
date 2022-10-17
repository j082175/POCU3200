#pragma once
#include <vector>

namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	public:
		SmartStack();

		void Push(T value);
		T Pop();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();

	private:
		std::vector<T> mVec;
		T mMax = T();
		T mMin = T();
		enum { MAX_SIZE = 128 };
	};

	template<typename T>
	inline SmartStack<T>::SmartStack()
	{
	}

	template<typename T>
	inline void SmartStack<T>::Push(T value)
	{
		// O(1)
		mVec.push_back(value);
	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		// O(1)
		T value = mVec.back();
		mVec.pop_back();
		return value;
	}

	template<typename T>
	inline T SmartStack<T>::Peek()
	{
		return mVec.back();
	}

	template<typename T>
	inline T SmartStack<T>::GetMax()
	{
		//// O(1)
		//if (mVec.size() == 0)
		//{
		//	return std::numeric_limits<T>::min();
		//}

		//T maxValue = mVec[0];
		//for (std::vector<int>::iterator i = mVec.begin() + 1; i != mVec.end(); i++)
		//{
		//	if (*i > maxValue)
		//	{
		//		maxValue = *i;
		//	}
		//}

		//return maxValue;

				// O(1)
		if (mVec.size() == 0)
		{
			return std::numeric_limits<T>::min();
		}

		T maxValue = mVec[0];
		for (size_t i = 1; i < mVec.size(); i++)
		{
			if (mVec[i] > maxValue)
			{
				maxValue = mVec[i];
			}
		}

		return maxValue;
	}

	template<typename T>
	inline T SmartStack<T>::GetMin()
	{
		// O(1)
		if (mVec.size() == 0)
		{
			return std::numeric_limits<T>::max();
		}

		T minValue = mVec[0];
		for (size_t i = 1; i < mVec.size(); i++)
		{
			if (mVec[i] < minValue)
			{
				minValue = mVec[i];
			}
		}

		return minValue;
	}

	template<typename T>
	inline double SmartStack<T>::GetAverage()
	{
		return static_cast<double>(GetSum()) / mVec.size();
	}

	template<typename T>
	inline T SmartStack<T>::GetSum()
	{
		if (mVec.size() == 0)
		{
			return 0;
		}

		double sum = 0.;

		for (size_t i = 0; i < mVec.size(); i++)
		{
			sum += mVec[i];
		}

		return static_cast<T>(sum);
	}

	template<typename T>
	inline double SmartStack<T>::GetVariance()
	{
		double average = GetAverage();
		double powSum = 0.;

		double backupArr[MAX_SIZE] = { 0. };

		for (size_t i = 0; i < mVec.size(); i++)
		{
			backupArr[i] = static_cast<double>(mVec[i]);
			backupArr[i] -= average;
			backupArr[i] *= backupArr[i];
			powSum += backupArr[i];
		}

		return powSum / mVec.size();
	}

	template<typename T>
	inline double SmartStack<T>::GetStandardDeviation()
	{
		return std::sqrt(GetVariance());
	}

	template<typename T>
	inline unsigned int SmartStack<T>::GetCount()
	{
		return static_cast<unsigned>(mVec.size());
	}
}