#pragma once
#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		~Motorcycle();

		unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;

		unsigned int TravelSpeed();

	private:
		enum 
		{
			MAX_NUM = 2
		};

	};
}