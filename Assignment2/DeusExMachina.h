#pragma once

#include "Vehicle.h"

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

		Vehicle* GetVehicle(unsigned int index) const;

		static void Destroy();
	private:
		enum 
		{
			MAX_SIZE = 10
		};

		static DeusExMachina* mDeusPtr;
		static unsigned int mSpeedCheckArr[MAX_SIZE];

		unsigned int mVehicleCount;

		Vehicle* mVehicleArr[MAX_SIZE] = { nullptr, };
	};
}