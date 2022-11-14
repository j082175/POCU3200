#pragma once

#include <queue>

namespace lab9
{
	template<typename T> // T는 클래스라고 가정, 복사, 대입 불가능, 필요하면 소멸자 구현
	class ObjectPool
	{
	public:
		ObjectPool(size_t maxPoolSize)
			: mMaxPoolSize(maxPoolSize)
			, mCurrentCount(0)
		{
		}

		~ObjectPool()
		{
			//delete[] mArr;
		}

		ObjectPool(const ObjectPool& other) = delete;
		ObjectPool& operator=(const ObjectPool& other) = delete;

		T* Get()
		{
			if (mCurrentCount == 0)
			{
				return new T;
			}

			T* value = mQueue.front();
			mQueue.pop();
			return value;
		}

		void Return(T* other)
		{
			if (mCurrentCount == mMaxPoolSize)
			{
				delete other;
				return;
			}
			
			mQueue.push(other);
			mCurrentCount++;
		}

		size_t GetFreeObjectCount() const
		{
			return mCurrentCount;
		}

		size_t GetMaxFreeObjectCount() const
		{
			return mMaxPoolSize;
		}

	private:
		size_t mMaxPoolSize;
		size_t mCurrentCount;
		std::queue<T*> mQueue;
	};
}