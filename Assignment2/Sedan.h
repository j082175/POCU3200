#pragma once
#include "Vehicle.h"

namespace assignment2
{
	class Trailer;

	class Sedan : Vehicle
	{
	public:
		Sedan();
		~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

	};
}