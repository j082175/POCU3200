#pragma once

#include <queue>
#include <memory>

namespace lab9
{
	template<typename T> // T는 클래스라고 가정, 복사, 대입 불가능, 필요하면 소멸자 구현
	class ObjectPool
	{
	public:
		ObjectPool(size_t maxPoolSize)
			: mMaxPoolSize(maxPoolSize)
		{
		}

		~ObjectPool()
		{
			size_t length = mQueue.size();
			for (size_t i = 0; i < length; i++)
			{
				delete mQueue.front();
				mQueue.front() = nullptr;
				mQueue.pop();
			}
		}

		ObjectPool(const ObjectPool& other) = delete;
		ObjectPool& operator=(const ObjectPool& other) = delete;

		T* Get()
		{
			if (mQueue.size() == 0)
			{
				return new T;
			}

			T* value = mQueue.front();
			mQueue.pop();
			return value;
		}

		void Return(T* other)
		{
			if (mQueue.size() == mMaxPoolSize)
			{
				delete other;
				return;
			}
			
			mQueue.push(other);
		}

		size_t GetFreeObjectCount() const
		{
			return mQueue.size();
		}

		size_t GetMaxFreeObjectCount() const
		{
			return mMaxPoolSize;
		}

	private:
		size_t mMaxPoolSize;
		std::queue<T*> mQueue;

	};
}