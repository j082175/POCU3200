#pragma once
#include "Lawn.h"

namespace lab5
{
	class CircleLawn : public Lawn
	{
	public:
		CircleLawn(unsigned int radius);

		unsigned int GetArea() const; // 반환단위 : m^2
	};
}



