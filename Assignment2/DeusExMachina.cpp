#include "DeusExMachina.h"
#include <iostream>

namespace assignment2
{
	DeusExMachina* DeusExMachina::mDeusPtr = nullptr;

	unsigned int DeusExMachina::mFurthestIndex = 0;
	
	static unsigned int mSpeedCheckArr[MAX_SIZE] = { 0, };

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mDeusPtr == nullptr)
		{
			mDeusPtr = new DeusExMachina;
		}

		return mDeusPtr;
	}

	DeusExMachina::DeusExMachina()
		: mVehicleCount(0)
	{
		for (size_t i = 0; i < MAX_SIZE; i++)
		{
			mVehicleArr[i] = nullptr;
		}
	}

	void DeusExMachina::Travel() const
	{
		// GetMaxSpeed()
		// km/h

		for (size_t i = 0; i < mVehicleCount; i++)
		{
			mSpeedCheckArr[i] += mVehicleArr[i]->TravelSpeed();
		}

		unsigned int max = 0;

		for (size_t i = 1; i < mVehicleCount; i++)
		{
			if (mSpeedCheckArr[i] > mSpeedCheckArr[max])
			{
				max = i;
			}
		}

		mFurthestIndex = max;

		std::cout << std::endl;
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (vehicle == nullptr || mVehicleCount >= MAX_SIZE)
		{
			return false;
		}

		//for (int i = mVehicleCount; i >= 1; i--)
		//{
		//	mVehicleArr[i] = mVehicleArr[i - 1];
		//}

		//mVehicleArr[0] = vehicle;
		//++mVehicleCount;

		mVehicleArr[mVehicleCount] = vehicle;
		mVehicleCount++;

		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (mVehicleCount <= i)
		{
			return false;
		}

		delete mVehicleArr[i];

		for (size_t j = i; j < mVehicleCount - 1; j++)
		{
			mVehicleArr[j] = mVehicleArr[j + 1];
		}

		--mVehicleCount;
		mVehicleArr[mVehicleCount] = nullptr;

		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mVehicleCount == 0)
		{
			return nullptr;
		}

		return mVehicleArr[mFurthestIndex];
	}
}