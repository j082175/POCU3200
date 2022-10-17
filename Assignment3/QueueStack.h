#pragma once
#include <vector>
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
		//std::queue<std::vector<T>*> mQueue;
		std::queue<SmartStack<T>*> mQueue;
		unsigned int mMaxStackSize;
	};
	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
	{
		//mQueue.push(new std::vector<T>());
		mQueue.push(new SmartStack<T>());
	}
	template<typename T>
	inline void QueueStack<T>::Enqueue(T value)
	{
		//if (mQueue.back()->size() >= mMaxStackSize)
		//{
		//	mQueue.push(new std::vector<T>());
		//}
		//mQueue.back()->push_back(value);

		if (mQueue.back()->GetCount() >= mMaxStackSize)
		{
			mQueue.push(new SmartStack<T>());
		}
		mQueue.back()->Push(value);
	}
	template<typename T>
	inline T QueueStack<T>::Peek()
	{
		return mQueue.front()->Peek();
	}
	template<typename T>
	inline T QueueStack<T>::Dequeue()
	{
		return mQueue.front()->Pop();
	}
	template<typename T>
	inline T QueueStack<T>::GetMax()
	{
		if (mQueue.empty())
		{
			return std::numeric_limits<T>::min();
		}

		T maxValue = mQueue.front()->GetMax();
		size_t length = mQueue.size();

		std::queue<SmartStack<T>*> bQ = mQueue;
		mQueue.pop();

		for (size_t i = 1; i < length; i++)
		{
			if (mQueue.front()->GetMax() > maxValue)
			{
				maxValue = mQueue.front()->GetMax();
			}
		}

		mQueue = bQ;
		return maxValue;
	}
	template<typename T>
	inline T QueueStack<T>::GetMin()
	{
		if (mQueue.empty())
		{
			return std::numeric_limits<T>::max();
		}

		T minValue = mQueue.front()->GetMin();
		size_t length = mQueue.size();

		std::queue<SmartStack<T>*> bQ = mQueue;
		mQueue.pop();

		for (size_t i = 1; i < length; i++)
		{
			if (mQueue.front()->GetMin() < minValue)
			{
				minValue = mQueue.front()->GetMin();
			}
		}

		mQueue = bQ;
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

		std::queue<SmartStack<T>*> bQ = mQueue;
		size_t length = mQueue.size();

		for (size_t i = 0; i < length; i++)
		{
			sum += mQueue.front()->GetSum();
			mQueue.pop();
		}

		mQueue = bQ;
		return static_cast<T>(sum);
	}
	template<typename T>
	inline unsigned int QueueStack<T>::GetCount()
	{
		size_t length = mQueue.size();
		size_t totalLength = 0;
		std::queue<SmartStack<T>*> bQ = mQueue;

		for (size_t i = 0; i < length; i++)
		{
			totalLength += mQueue.front()->GetCount();
			mQueue.pop();
		}

		mQueue = bQ;
		return totalLength;
	}
	template<typename T>
	inline unsigned int QueueStack<T>::GetStackCount()
	{
		size_t length = mQueue.size();
		size_t stackCount = 0;
		std::queue<SmartStack<T>*> bQ = mQueue;

		for (size_t i = 0; i < length; i++)
		{
			bQ.pop();
			stackCount++;
		}

		return stackCount;
	}
}

