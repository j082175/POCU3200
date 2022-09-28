#include "Airplane.h"
#include "Boat.h"

#include <cmath>

namespace assignment2
{

	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
		, mMoveTime(0)
		, mRestTime(0)
	{
	}

	Airplane::Airplane(const Airplane& other)
		: Vehicle(other.GetMaxPassengersCount())
		, mMoveTime(0)
		, mRestTime(0)
	{
		for (size_t i = 0; i < other.GetPassengersCount(); i++)
		{
			this->AddPassenger(new Person(*other.GetPassenger(i)));
		}
	}

	Airplane::~Airplane()
	{
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(this->GetMaxPassengersCount() + boat.GetMaxPassengersCount());

		unsigned int thisCount = this->GetPassengersCount();
		unsigned int boatCount = boat.GetPassengersCount();
		
		for (size_t i = 0; i < thisCount; i++)
		{
			bp.AddPassenger(new Person(*this->GetPassenger(i)));
		}

		for (size_t i = 0; i < boatCount; i++)
		{
			bp.AddPassenger(new Person(*boat.GetPassenger(i)));
		}

		for (size_t i = 0; i < thisCount; i++)
		{
			this->RemovePassenger(0);
		}

		for (size_t i = 0; i < boatCount; i++)
		{
			boat.RemovePassenger(0);
		}

		return bp;
	}

	unsigned int Airplane::GetMaxSpeed() const
	{	
		return std::max(GetFlySpeed(), GetDriveSpeed());
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		const double e = 2.718281828459045235360287471352;

		double totalWeight = 0;

		for (size_t i = 0; i < GetPassengersCount(); i++)
		{
			totalWeight += GetPassenger(i)->GetWeight();
		}
		
		double speed = 200 * std::pow(e, ((-totalWeight + 800) / 500)); // 648

		return static_cast<unsigned int>(std::round(speed));
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		const double e = 2.718281828459045235360287471352;

		double totalWeight = 0;

		for (size_t i = 0; i < GetPassengersCount(); i++)
		{
			totalWeight += GetPassenger(i)->GetWeight();
		}

		double speed = 4 * std::pow(e, (-totalWeight + 400) / 70);

		return static_cast<unsigned int>(std::round(speed));
	}

	unsigned int Airplane::TravelSpeed()
	{
		const unsigned int MAX_MOVE_TIME = 1;
		const unsigned int MAX_REST_TIME = 3;

		if (mMoveTime != MAX_MOVE_TIME)
		{
			//Debugger::Debug("Airplane");
			++mMoveTime;
			return std::max(GetFlySpeed(), GetDriveSpeed());
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