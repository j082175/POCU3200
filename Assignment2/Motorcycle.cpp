#include "Motorcycle.h"
#include <cmath>

namespace assignment2
{
	static const unsigned int MAX_NUM = 2;

	static unsigned int mMoveTime = 0;
	static unsigned int mRestTime = 0;

	Motorcycle::Motorcycle()
		: Vehicle(MAX_NUM)
		, mMoveTime(0)
		, mRestTime(0)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		double totalWeight = 0;

		for (size_t i = 0; i < GetPassengersCount(); i++)
		{
			totalWeight += GetPassenger(i)->GetWeight();
		}


		double speed = std::max((-std::pow(totalWeight / 15, 3) + 2 * totalWeight + 400), static_cast<double>(0));

		return static_cast<unsigned int>(std::round(speed));
	}

	unsigned int Motorcycle::TravelSpeed()
	{
		const unsigned int MAX_MOVE_TIME = 5;
		const unsigned int MAX_REST_TIME = 1;

		if (mMoveTime != MAX_MOVE_TIME)
		{
			//Debugger::Debug("Motorcycle");
			++mMoveTime;
			return GetDriveSpeed();
		}

		++mRestTime;

		if (mRestTime == MAX_REST_TIME)
		{
			mMoveTime = 0;
			mRestTime = 0;
		}

		return 0;
	}
}