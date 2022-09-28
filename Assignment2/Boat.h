#pragma once
#include "Vehicle.h"
#include "ISailable.h"
#include "Boatplane.h"

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();

		Boatplane operator+(Airplane& plane);

		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;

		unsigned int TravelSpeed();

	private:
		unsigned int mMoveTime;
		unsigned int mRestTime;
	};
}