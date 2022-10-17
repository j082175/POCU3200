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
		template<typename T1, typename T2, typename T3>
		struct third_pair
		{
			T1 first;
			T2 second;
			T3 third;
		};
		std::stack<third_pair<T, T, T>> mStack;
	};

	template<typename T>
	inline SmartStack<T>::SmartStack()
	{
	}

	template<typename T>
	inline void SmartStack<T>::Push(T value)
	{
		// O(1)
		T st_min;
		T st_max;

		st_min = mStack.empty() ? value : std::min(value, mStack.top().second);
		st_max = mStack.empty() ? value : std::max(value, mStack.top().third);
		mStack.push({ value, st_min, st_max });
		
		//mStack.push(value);
	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		// O(1)
		T value = mStack.top().first;
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
		return mStack.top().first;
	}

	template<typename T>
	inline T SmartStack<T>::GetMax()
	{
		//// O(1)

		if (mStack.size() == 0)
		{
			return std::numeric_limits<T>::lowest();
		}

		//std::stack<third_pair<T, T, T>> bS(mStack);
		//T maxValue = bS.top().first;
		//bS.pop();
		//size_t length = mStack.size();
		//for (size_t i = 1; i < length; i++)
		//{
		//	if (bS.top().first > maxValue)
		//	{
		//		maxValue = bS.top().first;
		//	}
		//	bS.pop();
		//}

		//return maxValue;

		return mStack.top().third;
	}

	template<typename T>
	inline T SmartStack<T>::GetMin()
	{
		// O(1)
		if (mStack.size() == 0)
		{
			return std::numeric_limits<T>::max();
		}

		//std::stack<third_pair<T, T, T>> bS(mStack);
		//T minValue = bS.top().first;
		//bS.pop();
		//size_t length = mStack.size();
		//for (size_t i = 1; i < length; i++)
		//{
		//	if (bS.top().first < minValue)
		//	{
		//		minValue = bS.top().first;
		//	}
		//	bS.pop();
		//}

		//return minValue;

		return mStack.top().second;
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
		std::stack<third_pair<T, T, T>> bS(mStack);

		for (size_t i = 0; i < length; i++)
		{
			sum += bS.top().first;
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
		std::stack<third_pair<T, T, T>> bS(mStack);

		for (size_t i = 0; i < length; i++)
		{
			backup = static_cast<double>(bS.top().first);
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