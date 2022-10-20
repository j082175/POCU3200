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
		struct ThirdPair 
		{
			T first;
			T second;
			T third;
			double sum;
			double powSum;
		};

		double mTotalSum;
		double mTotalPowSum;

		std::stack<ThirdPair> mStack;
	};

	template<typename T>
	inline SmartStack<T>::SmartStack()
		: mTotalSum(0)
		, mTotalPowSum(0)
	{
	}

	template<typename T>
	inline void SmartStack<T>::Push(T value)
	{
		// O(1)
		T st_min = mStack.empty() ? value : std::min(value, mStack.top().second);
		T st_max = mStack.empty() ? value : std::max(value, mStack.top().third);

		mStack.push({ value, st_min, st_max });
		// variance 
		// ºÐ»êÀº  'Á¦°öÀÇ Æò±Õ' »©±â 'Æò±ÕÀÇ Á¦°ö'

		double powSum = 0.;

		size_t length = mStack.size();

		powSum += static_cast<double>(mStack.top().first);

		mTotalSum += powSum;
		mTotalPowSum += powSum * powSum;

		mStack.top().sum = mTotalSum;
		mStack.top().powSum += mTotalPowSum;
	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		// O(1)
		T value = mStack.top().first;

		mStack.pop();
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

		return static_cast<T>(mStack.top().sum);
	}

	template<typename T>
	inline double SmartStack<T>::GetVariance()
	{
		size_t length = mStack.size();

		double result = (mStack.top().powSum / length) - ((mStack.top().sum / length) * (mStack.top().sum / length));

		return result;
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