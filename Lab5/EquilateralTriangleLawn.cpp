#include "EquilateralTriangleLawn.h"
#include <cmath>

lab5::EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int length)
	: Lawn(length, static_cast<unsigned int>(std::round(std::sqrt(3) / 2 * length)))
{
}

unsigned int lab5::EquilateralTriangleLawn::GetArea() const
{
	return static_cast<unsigned int>(std::round(mWidth * std::sqrt(3) / 2 * mWidth / 2));
}

unsigned int lab5::EquilateralTriangleLawn::GetMinimumFencesCount() const
{
	// 0.25m
	return mWidth * 3 * 4;
}

unsigned int lab5::EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
{
	double result = 0;

	switch (fenceType)
	{
	case lab5::RED_CEDAR:
		result = GetMinimumFencesCount() * 6 / 4.0;
		break;
	case lab5::SPRUCE:
		result = GetMinimumFencesCount() * 7 / 4.0;
		break;
	default:
		break;
	}

	return static_cast<unsigned int>(std::round(result));
}
