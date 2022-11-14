#pragma once

#include <queue>
#include <memory>

namespace lab9
{
	template<typename T> // T�� Ŭ������� ����, ����, ���� �Ұ���, �ʿ��ϸ� �Ҹ��� ����
	class ObjectPool
	{
	public:
		ObjectPool(size_t maxPoolSize)
			: mMaxPoolSize(maxPoolSize)
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
			if (mQueue.size() == 0)
			{
				return new T;
			}

			T* value = *mQueue.front().get();
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
			
			//mQueue.push(other);

			mQueue.push(std::make_unique<T*>(other));
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
		//std::queue<T*> mQueue;
		std::queue<std::unique_ptr<T*>> mQueue;

	};
}