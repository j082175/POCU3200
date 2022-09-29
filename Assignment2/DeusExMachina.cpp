#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::mDeusPtr = nullptr;
	unsigned int DeusExMachina::mSpeedCheckArr[MAX_SIZE] = { 0, };

	void DeusExMachina::Destroy()
	{
		delete mDeusPtr;
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mDeusPtr == nullptr)
		{
			mDeusPtr = new DeusExMachina;
			atexit(Destroy);
		}

		return mDeusPtr;
	}

	DeusExMachina::DeusExMachina()
		: mVehicleCount(0)
	{
		//for (size_t i = 0; i < MAX_SIZE; i++)
		//{
		//	mVehicleArr[i] = nullptr;
		//}
	}

	DeusExMachina::~DeusExMachina()
	{
		for (size_t i = 0; i < mVehicleCount; i++)
		{
			delete mVehicleArr[i];
		}

		mDeusPtr = nullptr;
	}

	void DeusExMachina::Travel() const
	{
		// GetMaxSpeed()
		// km/h

		for (size_t i = 0; i < mVehicleCount; i++)
		{
			mSpeedCheckArr[i] += mVehicleArr[i]->TravelSpeed();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (vehicle == nullptr)
		{
			return false;
		}

		if (mVehicleCount >= MAX_SIZE)
		{
			return false;
		}

		//for (size_t i = mVehicleCount; i >= 1; i--)
		//{
		//	mVehicleArr[i] = mVehicleArr[i - 1];
		//}

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

		unsigned int max = mVehicleCount - 1;

		for (int i = mVehicleCount - 2; i >= 0; i--)
		{
			if (mSpeedCheckArr[i] > mSpeedCheckArr[max])
			{
				max = i;
			}
		}

		return mVehicleArr[max];
	}

	Vehicle* DeusExMachina::GetVehicle(unsigned int index) const
	{
		if (mVehicleCount <= index)
		{
			return nullptr;
		}

		return mVehicleArr[index];
	}
}