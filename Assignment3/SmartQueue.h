#pragma once
#include <queue>

namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		SmartQueue(const SmartQueue& other)
		{
			size_t length = other.mQueue.size();
			std::queue<T*> bQ(other.mQueue);

			for (size_t i = 0; i < length; i++)
			{
				mQueue.push(new T(*bQ.front()));
				bQ.pop();
			}
		}

		~SmartQueue()
		{
			for (size_t i = 0; i < mQueue.size(); i++)
			{
				delete mQueue.front();
				mQueue.pop();
			}
		}

		void Enqueue(T value);
		T& Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();

		T& Back()
		{
			return *mQueue.back();
		}

	private:
		std::queue<T*> mQueue;
		enum { MAX_SIZE = 128 };
	};

	template<typename T>
	inline SmartQueue<T>::SmartQueue()
	{}

	template<typename T>
	inline void SmartQueue<T>::Enqueue(T value)
	{
		//mQueue.push(value);
		mQueue.push(new T(value));
	}

	template<typename T>
	inline T& SmartQueue<T>::Peek()
	{
		//return mQueue.front();
		return *mQueue.front();
	}

	template<typename T>
	inline T SmartQueue<T>::Dequeue()
	{
		//T value = mQueue.front();
		T value = *mQueue.front();

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

		//std::queue<T> bQ = mQueue;
		std::queue<T*> bQ = mQueue;

		//T maxValue = bQ.front();
		T maxValue = *bQ.front();

		bQ.pop();

		for (size_t i = 1; i < length; i++)
		{
			if (*bQ.front() > maxValue)
			{
				maxValue = *bQ.front();
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
		std::queue<T*> bQ = mQueue;

		T minValue = *bQ.front();
		bQ.pop();

		for (size_t i = 1; i < length; i++)
		{
			if (*bQ.front() < minValue)
			{
				minValue = *bQ.front();
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

		std::queue<T*> bQ = mQueue;
		size_t length = mQueue.size();
		T sum = T();

		for (size_t i = 0; i < length; i++)
		{
			sum += *bQ.front();
			bQ.pop();
		}

		return sum;
	}

	template<typename T>
	inline double SmartQueue<T>::GetVariance()
	{
		double average = GetAverage();
		double powSum = 0.;

		double backup;

		std::queue<T*> bQ = mQueue;
		size_t length = mQueue.size();

		for (size_t i = 0; i < length; i++)
		{
			backup = static_cast<double>(*bQ.front());
			backup -= average;
			backup *= backup;
			powSum += backup;

			bQ.pop();
		}

		return powSum / length;
	}

	template<typename T>
	inline double SmartQueue<T>::GetStandardDeviation()
	{
		return std::sqrt(GetVariance());
	}

	template<typename T>
	inline unsigned int SmartQueue<T>::GetCount()
	{
		return mQueue.size();
	}

}

