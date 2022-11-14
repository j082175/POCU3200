#pragma once

#include <queue>

namespace lab9
{
	template<typename T> // T�� Ŭ������� ����, ����, ���� �Ұ���, �ʿ��ϸ� �Ҹ��� ����
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

		T* Get() const
		{
			if (mCurrentCount == 0)
			{
				return new T;
			}

			return mArr.front();
		}

		void Return(T* other)
		{
			if (mCurrentCount == mMaxPoolSize)
			{
				delete other;
				return;
			}

			mArr.push(other);
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
		std::queue<T*> mArr;
	};
}