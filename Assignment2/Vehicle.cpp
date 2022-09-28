#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengersCount(maxPassengersCount)
		, mPassengersCount(0)
	{
		// 질문 1. for 문을 사용하지 않고 개체배열을 초기화하는 방법은 없는것인가? (최적화 때문에)
		for (size_t i = 0; i < MAX_SIZE; i++)
		{
			mPassengersArr[i] = nullptr;
		}
	}

	Vehicle::~Vehicle()
	{
		for (size_t i = 0; i < mPassengersCount; i++)
		{
			delete mPassengersArr[i];
		}
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (person == nullptr)
		{
			return false;
		}

		mPassengersArr[mPassengersCount] = person;
		mPassengersCount++;

		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (mPassengersCount <= i)
		{
			return false;
		}

		delete mPassengersArr[i];

		for (size_t j = i; j < mPassengersCount - 1; j++)
		{
			mPassengersArr[j] = mPassengersArr[j + 1];
		}

		mPassengersCount--;
		mPassengersArr[mPassengersCount] = nullptr;

		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mPassengersCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (mPassengersCount <= i)
		{
			return nullptr;
		}

		return mPassengersArr[i];
	}
}