#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mPassengersCount(0)
		, mMaxPassengersCount(maxPassengersCount)
	{
		if (maxPassengersCount > MAX_SIZE)
		{
			mMaxPassengersCount = MAX_SIZE;
		}

		//// 질문 1. for 문을 사용하지 않고 개체배열을 초기화하는 방법은 없는것인가? (최적화 때문에)
		//for (size_t i = 0; i < MAX_SIZE; i++)
		//{
		//	mPassengersArr[i] = nullptr;
		//}
	}

	Vehicle::~Vehicle()
	{
		for (size_t i = 0; i < mPassengersCount; i++)
		{
			delete mPassengersArr[i];
		}
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mMaxPassengersCount(other.mMaxPassengersCount)
		, mPassengersCount(other.mPassengersCount)
	{
		//// 질문 1. for 문을 사용하지 않고 개체배열을 초기화하는 방법은 없는것인가? (최적화 때문에)
		//for (size_t i = 0; i < MAX_SIZE; i++)
		//{
		//	mPassengersArr[i] = nullptr;
		//}

		for (size_t i = 0; i < mPassengersCount; i++)
		{
			mPassengersArr[i] = new Person(*other.GetPassenger(i));
		}


	}

	Vehicle& Vehicle::operator=(const Vehicle& other)
	{
		if (this == &other)
		{
			return *this;
		}

		for (size_t i = 0; i < mPassengersCount; i++)
		{
			delete mPassengersArr[i];
		}

		mMaxPassengersCount = other.mMaxPassengersCount;
		mPassengersCount = other.mPassengersCount;

		for (size_t i = 0; i < mPassengersCount; i++)
		{
			mPassengersArr[i] = new Person(*other.GetPassenger(i));
		}

		return *this;
	}

	Vehicle::Vehicle(Vehicle&& other) noexcept
		: mMaxPassengersCount(other.mMaxPassengersCount)
		, mPassengersCount(other.mPassengersCount)
	{
		for (size_t i = 0; i < mPassengersCount; i++)
		{
			mPassengersArr[i] = other.mPassengersArr[i];
			delete other.mPassengersArr[i];
		}

		other.mPassengersCount = 0;
	}

	Vehicle& Vehicle::operator=(Vehicle&& other) noexcept
	{
		if (this == &other)
		{
			return *this;
		}

		for (size_t i = 0; i < mPassengersCount; i++)
		{
			delete mPassengersArr[i];
		}

		mPassengersCount = other.mPassengersCount;

		for (size_t i = 0; i < mPassengersCount; i++)
		{
			mPassengersArr[i] = other.mPassengersArr[i];
			delete other.mPassengersArr[i];
		}

		other.mPassengersCount = 0;

		return *this;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (person == nullptr)
		{
			return false;
		}

		if (mPassengersCount >= mMaxPassengersCount)
		{
			return false;
		}

		// person 중복검사
		for (size_t i = 0; i < mPassengersCount; i++)
		{
			if (mPassengersArr[i] == person)
			{
				return false;
			}
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

	//void Vehicle::SetMemoryNullNoDelete()
	//{
	//	mPassengersCount = 0;
	//}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (mPassengersCount <= i)
		{
			return nullptr;
		}

		return mPassengersArr[i];
	}
}