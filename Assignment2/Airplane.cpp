#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

#include <cmath>

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(0);
		return bp;
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		return 0;
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		return 0;
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		const double e = 2.718281828459045235360287471352;

		unsigned int totalWeight = 0;

		for (size_t i = 0; i < mPersonCount; i++)
		{
			totalWeight += mPersonArr[i]->GetWeight();
		}

		double speed = 4 * std::pow(e, (-static_cast<int>(totalWeight) + 400) / 70);

		return static_cast<unsigned int>(std::round(speed));
	}
}