#include "RectangleLawn.h"
#include <cmath>

lab5::RectangleLawn::RectangleLawn(unsigned width, unsigned height)
	: Lawn(width, height)
{
}

unsigned int lab5::RectangleLawn::GetArea() const
{
	return mWidth * mHeight;
}

unsigned int lab5::RectangleLawn::GetMinimumFencesCount() const
{
	// 0.25m

	double widthCount = mWidth * 4 * 2;
	double heightCount = mHeight * 4 * 2;

	return static_cast<unsigned int>(widthCount + heightCount);
}

unsigned int lab5::RectangleLawn::GetFencePrice(eFenceType fenceType) const
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

