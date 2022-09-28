#pragma once

#include "Vehicle.h"
#define MAX_SIZE 10

namespace assignment2
{

	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();

		DeusExMachina();

		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;

		~DeusExMachina();

	private:
		//static constexpr unsigned int MAX_SIZE = 10;

		static DeusExMachina* mDeusPtr;
		unsigned int mVehicleCount;
		Vehicle* mVehicleArr[MAX_SIZE];
		static unsigned int mFurthestIndex;
	};
}