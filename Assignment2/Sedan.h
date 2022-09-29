#pragma once
#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

		unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;

		unsigned int TravelSpeed();

	private:
		unsigned int getSpeed(unsigned int maxMoveTime, unsigned int maxRestTime);

	private:
		enum 
		{
			MAX_NUM = 4
		};

		const Trailer* mT;

		unsigned int mMoveTime;
		unsigned int mRestTime;
	};
}