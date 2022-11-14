#pragma once

#include "IceCube.h" // 지우기

template<typename T> // T는 클래스라고 가정, 복사, 대입 불가능, 필요하면 소멸자 구현
class ObjectPool
{
public:
	ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
		, mCurrentCount(0)
	{
		mArr = new T*[mMaxPoolSize];
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

		size_t max = mArr[0]->GetLiveCount();
		size_t index = 0;

		for (size_t i = 1; i < mCurrentCount; i++)
		{
			if (max < mArr[i]->GetLiveCount())
			{
				max = mArr[i]->GetLiveCount();
				index = i;
			}
		}

		return mArr[index];
	}

	void Return(T* other)
	{
		if (mCurrentCount == mMaxPoolSize)
		{
			delete other;
		}

		mArr[mCurrentCount++] = other;
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
	T** mArr;
};

