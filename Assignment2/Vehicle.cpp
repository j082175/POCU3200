#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengersCount(maxPassengersCount)
		, mPersonCount(0)
	{
	}

	Vehicle::~Vehicle()
	{
		for (size_t i = 0; i < mPersonCount; i++)
		{
			delete mPersonArr[i];
		}
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (person == nullptr)
		{
			return false;
		}

		mPersonArr[mPersonCount] = person;
		mPersonCount++;

		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (mPersonCount <= i)
		{
			return false;
		}

		delete mPersonArr[i];

		for (size_t j = i; j < mPersonCount - 1; j++)
		{
			mPersonArr[j] = mPersonArr[j + 1];
		}

		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mPersonCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (mPersonCount <= i)
		{
			return nullptr;
		}

		return mPersonArr[i];
	}
}