#pragma once
#include <stack>
#include <cmath>


namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	public:
		SmartStack();
		SmartStack(const SmartStack<T>& other)
			: mStack(other.mStack)
		{

		}
		
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
		std::stack<T> mStack;
		T mMax;
		T mMin;
	};

	template<typename T>
	inline SmartStack<T>::SmartStack()
		: mMax(std::numeric_limits<T>::lowest())
		, mMin(std::numeric_limits<T>::max())
	{
	}

	template<typename T>
	inline void SmartStack<T>::Push(T value)
	{
		// O(1)
		mStack.push(value);
		if (value > mMax)
		{
			mMax = value;
		}

		if (value < mMin)
		{
			mMin = value;
		}
	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		// O(1)
		T value = mStack.top();
		mStack.pop();

		//T value2 = mStack.top();
		//if (value2 > mMax)
		//{
		//	mMax = value2;
		//}

		//if (value2 < mMin)
		//{
		//	mMin = value2;
		//}

		return value;
	}

	template<typename T>
	inline T SmartStack<T>::Peek()
	{
		return mStack.top();
	}

	template<typename T>
	inline T SmartStack<T>::GetMax()
	{
		//// O(1)

		if (mStack.size() == 0)
		{
			return std::numeric_limits<T>::lowest();
		}

		std::stack<T> bS(mStack);
		T maxValue = bS.top();
		bS.pop();
		size_t length = mStack.size();
		for (size_t i = 1; i < length; i++)
		{
			if (bS.top() > maxValue)
			{
				maxValue = bS.top();
			}
			bS.pop();
		}

		return maxValue;

		//return mMax;
	}

	template<typename T>
	inline T SmartStack<T>::GetMin()
	{
		// O(1)
		if (mStack.size() == 0)
		{
			return std::numeric_limits<T>::max();
		}

		std::stack<T> bS(mStack);
		T minValue = bS.top();
		bS.pop();
		size_t length = mStack.size();
		for (size_t i = 1; i < length; i++)
		{
			if (bS.top() < minValue)
			{
				minValue = bS.top();
			}
			bS.pop();
		}

		return minValue;

		//return mMin;
	}

	template<typename T>
	inline double SmartStack<T>::GetAverage()
	{
		return static_cast<double>(GetSum()) / mStack.size();
	}

	template<typename T>
	inline T SmartStack<T>::GetSum()
	{
		if (mStack.size() == 0)
		{
			return 0;
		}

		double sum = 0.;
		size_t length = mStack.size();
		std::stack<T> bS(mStack);

		for (size_t i = 0; i < length; i++)
		{
			sum += bS.top();
			bS.pop();
		}

		return static_cast<T>(sum);
	}

	template<typename T>
	inline double SmartStack<T>::GetVariance()
	{
		double average = GetAverage();
		double powSum = 0.;

		double backup;

		size_t length = mStack.size();
		std::stack<T>bS(mStack);

		for (size_t i = 0; i < length; i++)
		{
			backup = static_cast<double>(bS.top());
			backup -= average;
			backup *= backup;
			powSum += backup;

			bS.pop();
		}
		return powSum / length;
	}

	template<typename T>
	inline double SmartStack<T>::GetStandardDeviation()
	{
		return std::sqrt(GetVariance());
	}

	template<typename T>
	inline unsigned int SmartStack<T>::GetCount()
	{
		return static_cast<unsigned>(mStack.size());
	}
}