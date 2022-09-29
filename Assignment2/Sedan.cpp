#include "Sedan.h"

#include "Trailer.h"

namespace assignment2
{
	static const unsigned int MAX_NUM = 4;

	Sedan::Sedan()
		: Vehicle(MAX_NUM)
		, mT(nullptr)
		, mMoveTime(0)
		, mRestTime(0)
	{
	}

	Sedan::~Sedan()
	{
		delete mT;
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (trailer == nullptr || mT != nullptr)
		{
			return false;
		}

		mT = trailer;

		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mT == nullptr)
		{
			return false;
		}

		delete mT;
		mT = nullptr;

		return true;
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int totalWeight = 0;
		unsigned int speed = 0;

		for (size_t i = 0; i < GetPassengersCount(); i++)
		{
			totalWeight += GetPassenger(i)->GetWeight();
		}

		if (mT != nullptr)
		{
			totalWeight += mT->GetWeight();
		}

		//if (totalWeight <= 80)
		//{
		//	speed = 480;
		//}
		//else if (totalWeight > 80)
		//{
		//	speed = 458;
		//}
		//else if (totalWeight > 160)
		//{
		//	speed = 400;
		//}
		//else if (totalWeight > 260)
		//{
		//	speed = 380;
		//}
		//else if (totalWeight > 350)
		//{
		//	speed = 300;
		//}

		if (totalWeight > 350)
		{
			speed = 300;
		}
		else if (totalWeight > 260)
		{
			speed = 380;
		}
		else if (totalWeight > 160)
		{
			speed = 400;
		}
		else if (totalWeight > 80)
		{
			speed = 458;
		}
		else if (totalWeight <= 80)
		{
			speed = 480;
		}

		return speed;
	}

	unsigned int Sedan::TravelSpeed()
	{
		if (mT == nullptr)
		{
			return getSpeed(5, 1);
		}
		else
		{
			return getSpeed(5, 2);
		}
	}

	unsigned int Sedan::getSpeed(unsigned int maxMoveTime, unsigned int maxRestTime)
	{
		if (mMoveTime != maxMoveTime)
		{
			//Debugger::Debug("Sedan");
			++mMoveTime;
			return GetDriveSpeed();
		}

		++mRestTime;

		if (mRestTime == maxRestTime)
		{
			mMoveTime = 0;
			mRestTime = 0;
		}

		return 0;
	}
}