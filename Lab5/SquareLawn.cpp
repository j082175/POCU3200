#include "SquareLawn.h"

lab5::SquareLawn::SquareLawn(unsigned width)
	: RectangleLawn(width, width)
{
}

unsigned int lab5::SquareLawn::GetArea() const
{
	return RectangleLawn::GetArea();
}

unsigned int lab5::SquareLawn::GetMinimumFencesCount() const
{
	return RectangleLawn::GetMinimumFencesCount();
}

unsigned int lab5::SquareLawn::GetFencePrice(eFenceType fenceType) const
{
	return RectangleLawn::GetFencePrice(fenceType);
}
