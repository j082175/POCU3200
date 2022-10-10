#include "CircleLawn.h"
#include <cmath>

lab5::CircleLawn::CircleLawn(unsigned int radius)
	: Lawn(2 * radius, 2 * radius)
{
}

unsigned int lab5::CircleLawn::GetArea() const
{
	double pi = 3.14;
	double radius = mWidth / 2.0;
	return static_cast<unsigned int>(std::round(pi * radius * radius));
}