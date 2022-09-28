#include "Boatplane.h"
#include <cmath>

namespace assignment2
{

	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
		, mMoveTime(0)
		, mRestTime(0)
	{
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		return std::max(GetFlySpeed(), GetSailSpeed());
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		const double e = 2.718281828459045235360287471352;

		double totalWeight = 0;

		for (size_t i = 0; i < GetPassengersCount(); i++)
		{
			totalWeight += GetPassenger(i)->GetWeight();
		}

		double speed = 150 * std::pow(e, (-totalWeight + 500) / 300);

		return static_cast<unsigned int>(std::round(speed));
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		double totalWeight = 0;

		for (size_t i = 0; i < GetPassengersCount(); i++)
		{
			totalWeight += GetPassenger(i)->GetWeight();
		}

		double speed = std::max((800 - 1.7 * totalWeight), static_cast<double>(20));

		return static_cast<unsigned int>(std::round(speed));
	}

	unsigned int Boatplane::TravelSpeed()
	{
		const unsigned int MAX_MOVE_TIME = 1;
		const unsigned int MAX_REST_TIME = 3;

		if (mMoveTime != MAX_MOVE_TIME)
		{
			//Debugger::Debug("Boatplane");
			++mMoveTime;
			return std::max(GetFlySpeed(), GetSailSpeed());
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