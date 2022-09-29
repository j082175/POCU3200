#pragma once

#include "Vehicle.h"

namespace assignment2
{

	class DeusExMachina
	{
	public:
		static void Destroy();

		static DeusExMachina* GetInstance();

		DeusExMachina();
		~DeusExMachina();

		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;

		Vehicle* GetVehicle(unsigned int index) const;

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