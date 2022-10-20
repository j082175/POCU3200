#pragma once
#include <queue>

namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
	public:
		SmartQueue();

		void Enqueue(T value);
		T Peek();
		T Dequeue();
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

		std::queue<ThirdPair> mQueue;
	};

	template<typename T>
	inline SmartQueue<T>::SmartQueue()
		: mTotalSum(0)
		, mTotalPowSum(0)
	{
	}

	template<typename T>
	inline void SmartQueue<T>::Enqueue(T value)
	{
		mQueue.push({ value });
		// variance 
		// ºÐ»êÀº  'Á¦°öÀÇ Æò±Õ' »©±â 'Æò±ÕÀÇ Á¦°ö'

		double powSum = 0.;

		size_t length = mQueue.size();

		powSum += static_cast<double>(mQueue.back().first);

		mTotalSum += powSum;
		mTotalPowSum += powSum * powSum;

		mQueue.back().sum = mTotalSum;
		mQueue.back().powSum += mTotalPowSum;
	}

	template<typename T>
	inline T SmartQueue<T>::Peek()
	{
		return mQueue.front().first;
	}

	template<typename T>
	inline T SmartQueue<T>::Dequeue()
	{
		T value = mQueue.front().first;

		mTotalSum = mQueue.back().sum - mQueue.front().sum;
		mTotalPowSum = mQueue.back().powSum - mQueue.front().powSum;

		mQueue.pop();
		return value;
	}

	template<typename T>
	inline T SmartQueue<T>::GetMax()
	{
		if (mQueue.size() == 0)
		{
			return std::numeric_limits<T>::lowest();
		}

		size_t length = mQueue.size();
		std::queue<ThirdPair> bQ = mQueue;

		T maxValue = bQ.front().first;
		bQ.pop();

		for (size_t i = 1; i < length; i++)
		{
			if (bQ.front().first > maxValue)
			{
				maxValue = bQ.front().first;
			}
			bQ.pop();
		}

		return maxValue;
	}

	template<typename T>
	inline T SmartQueue<T>::GetMin()
	{
		if (mQueue.empty())
		{
			return std::numeric_limits<T>::max();
		}

		size_t length = mQueue.size();
		std::queue<ThirdPair> bQ = mQueue;

		T minValue = bQ.front().first;
		bQ.pop();

		for (size_t i = 1; i < length; i++)
		{
			if (bQ.front().first < minValue)
			{
				minValue = bQ.front().first;
			}
			bQ.pop();
		}

		return minValue;
	}

	template<typename T>
	inline double SmartQueue<T>::GetAverage()
	{
		if (mQueue.empty())
		{
			return 0;
		}

		return static_cast<double>(GetSum()) / mQueue.size();
	}

	template<typename T>
	inline T SmartQueue<T>::GetSum()
	{
		if (mQueue.empty())
		{
			return 0;
		}

		std::queue<ThirdPair> bQ = mQueue;
		size_t length = bQ.size();
		T sum = T();

		for (size_t i = 0; i < length; i++)
		{
			sum += bQ.front().first;
			bQ.pop();
		}

		return sum;
	}

	template<typename T>
	inline double SmartQueue<T>::GetVariance()
	{
		size_t length = mQueue.size();

		double result = (mTotalPowSum / length) - ((mTotalSum / length) * (mTotalSum / length));
		return result;
	}

	template<typename T>
	inline double SmartQueue<T>::GetStandardDeviation()
	{
		return std::sqrt(GetVariance());
	}

	template<typename T>
	inline unsigned int SmartQueue<T>::GetCount()
	{
		return static_cast<unsigned int>(mQueue.size());
	}
}

