#pragma once
#include "Vehicle.h"
#include "IFlyable.h"
#include "IDrivable.h"

#include "Boatplane.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IFlyable, public IDrivable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		Boatplane operator+(Boat& boat);

		unsigned int GetMaxSpeed() const;
		unsigned int GetFlySpeed() const;
		unsigned int GetDriveSpeed() const;

		unsigned int TravelSpeed();

	//private:
	//	unsigned int mMoveTime;
	//	unsigned int mRestTime;
	};
}