#include "Boat.h"
#include "Airplane.h"
#include <cmath>

namespace assignment2
{

	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane bp(this->GetMaxPassengersCount() + plane.GetMaxPassengersCount());

		unsigned int thisCount = this->GetPassengersCount();
		unsigned int planeCount = plane.GetPassengersCount();

		for (size_t i = 0; i < planeCount; i++)
		{
			bp.AddPassenger(new Person(*plane.GetPassenger(i)));
		}

		for (size_t i = 0; i < thisCount; i++)
		{
			bp.AddPassenger(new Person(*this->GetPassenger(i)));
		}

		for (size_t i = 0; i < thisCount; i++)
		{
			this->RemovePassenger(thisCount - 1 - i);
		}

		for (size_t i = 0; i < planeCount; i++)
		{
			plane.RemovePassenger(planeCount - 1 - i);
		}

		return bp;
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	unsigned int Boat::GetSailSpeed() const
	{
		double totalWeight = 0;

		for (size_t i = 0; i < GetPassengersCount(); i++)
		{
			totalWeight += GetPassenger(i)->GetWeight();
		}

		double speed = std::max((800 - 10 * totalWeight), static_cast<double>(20));

		return static_cast<unsigned int>(std::round(speed));
	}

	unsigned int Boat::TravelSpeed()
	{
		const unsigned int MAX_MOVE_TIME = 2;
		const unsigned int MAX_REST_TIME = 1;

		if (mMoveTime != MAX_MOVE_TIME)
		{
			//Debugger::Debug("Boat");
			++mMoveTime;
			return GetSailSpeed();
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