#pragma once

#include "IceCube.h" // �����

template<typename T> // T�� Ŭ������� ����, ����, ���� �Ұ���, �ʿ��ϸ� �Ҹ��� ����
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

