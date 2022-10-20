#pragma once
#include <queue>
#include "SmartStack.h"

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);

		void Enqueue(T value);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount();
		unsigned int GetStackCount();

	private:
		std::queue<SmartStack<T>> mQueue;
		unsigned int mMaxStackSize;
	};
	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
	{
	}

	template<typename T>
	inline void QueueStack<T>::Enqueue(T value)
	{
		if (mMaxStackSize == 0)
		{
			return;
		}

		if (mQueue.empty())
		{
			mQueue.push(SmartStack<T>());
			mQueue.back().Push(value);
			return;
		}

		if (mQueue.back().GetCount() >= mMaxStackSize)
		{
			mQueue.push(SmartStack<T>());
		}
		mQueue.back().Push(value);
	}

	template<typename T>
	inline T QueueStack<T>::Peek()
	{
		return mQueue.front().Peek();
	}

	template<typename T>
	inline T QueueStack<T>::Dequeue()
	{
		T value = mQueue.front().Pop();
		if (mQueue.front().GetCount() == 0)
		{
			mQueue.pop();
		}
		return value;
	}

	template<typename T>
	inline T QueueStack<T>::GetMax()
	{
		if (mQueue.empty())
		{
			return std::numeric_limits<T>::lowest();
		}

		T maxValue = mQueue.front().GetMax();
		size_t length = mQueue.size();

		std::queue<SmartStack<T>> bQ = mQueue;
		bQ.pop();

		for (size_t i = 1; i < length; i++)
		{
			if (bQ.front().GetMax() > maxValue)
			{
				maxValue = bQ.front().GetMax();
			}
			bQ.pop();
		}

		return maxValue;
	}

	template<typename T>
	inline T QueueStack<T>::GetMin()
	{
		if (mQueue.empty())
		{
			return std::numeric_limits<T>::max();
		}

		T minValue = mQueue.front().GetMin();
		size_t length = mQueue.size();

		std::queue<SmartStack<T>> bQ = mQueue;
		bQ.pop();

		for (size_t i = 1; i < length; i++)
		{
			if (bQ.front().GetMin() < minValue)
			{
				minValue = bQ.front().GetMin();
			}
			bQ.pop();
		}

		return minValue;
	}

	template<typename T>
	inline double QueueStack<T>::GetAverage()
	{
		return static_cast<double>(GetSum()) / GetCount();
	}

	template<typename T>
	inline T QueueStack<T>::GetSum()
	{
		if (mQueue.empty())
		{
			return 0;
		}

		double sum = 0.;

		std::queue<SmartStack<T>> bQ = mQueue;
		size_t length = mQueue.size();

		for (size_t i = 0; i < length; i++)
		{
			sum += bQ.front().GetSum();
			bQ.pop();
		}

		return static_cast<T>(sum);
	}

	template<typename T>
	inline unsigned int QueueStack<T>::GetCount()
	{
		size_t length = mQueue.size();
		size_t totalLength = 0;
		std::queue<SmartStack<T>> bQ = mQueue;

		for (size_t i = 0; i < length; i++)
		{
			totalLength += bQ.front().GetCount();
			bQ.pop();
		}

		return totalLength;
	}

	template<typename T>
	inline unsigned int QueueStack<T>::GetStackCount()
	{
		size_t length = mQueue.size();
		size_t stackCount = 0;
		std::queue<SmartStack<T>> bQ = mQueue;

		for (size_t i = 0; i < length; i++)
		{
			bQ.pop();
			stackCount++;
		}

		return stackCount;
	}
}