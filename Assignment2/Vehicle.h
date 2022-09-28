#pragma once

#include "Person.h"

#include <iostream>
using namespace std;

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;

		virtual unsigned int TravelSpeed() = 0;

	private:
		enum
		{
			MAX_SIZE = 100
		};

		unsigned int mMaxPassengersCount; // 100보다 큰 경우는 없다고 가정해도 좋음.
		unsigned int mPassengersCount;
		const Person* mPassengersArr[MAX_SIZE];
	};
}