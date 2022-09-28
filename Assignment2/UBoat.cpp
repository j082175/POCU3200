#include "UBoat.h"
#include <cmath>

namespace assignment2
{
	static const unsigned int MAX_NUM = 50;

	UBoat::UBoat()
		: Vehicle(MAX_NUM)
		, mMoveTime(0)
		, mRestTime(0)
	{
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		return std::max(GetSailSpeed(), GetDiveSpeed());
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		double totalWeight = 0;

		for (size_t i = 0; i < GetPassengersCount(); i++)
		{
			totalWeight += GetPassenger(i)->GetWeight();
		}

		double speed = std::max((550 - totalWeight / 10), static_cast<double>(200));

		return static_cast<unsigned int>(std::round(speed));
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		double totalWeight = 0;

		for (size_t i = 0; i < GetPassengersCount(); i++)
		{
			totalWeight += GetPassenger(i)->GetWeight();
		}
		
		double speed = 500 * log((totalWeight + 150) / 150) + 30;

		return static_cast<unsigned int>(std::round(speed));
	}

	unsigned int UBoat::TravelSpeed()
	{
		const unsigned int MAX_MOVE_TIME = 2;
		const unsigned int MAX_REST_TIME = 4;

		if (mMoveTime != MAX_MOVE_TIME)
		{
			//Debugger::Debug("UBoat");
			++mMoveTime;
			return std::max(GetSailSpeed(), GetDiveSpeed());
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