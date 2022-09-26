#pragma once
#include "Vehicle.h"

namespace assignment2
{
	class Boatplane : Vehicle
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();
		unsigned int GetMaxSpeed() const;
	};
}