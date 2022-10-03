#include "Lawn.h"
#include <cmath>

namespace lab5
{
	Lawn::Lawn(unsigned width, unsigned height)
		: mWidth(width)
		, mHeight(height)
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const // 반환 단위 : 달러
	{
		unsigned int result = 0;
		switch (grassType)
		{
		case lab5::BERMUDA:
			result = 8 * GetArea();
			break;
		case lab5::BAHIA:
			result = 5 * GetArea();
			break;
		case lab5::BENTGRASS:
			result = 3 * GetArea();
			break;
		case lab5::PERENNIAL_RYEGRASS:
			result = static_cast<unsigned int>(std::round(GetArea() * 2.5));
			break;
		case lab5::ST_AUGUSTINE:
			result = static_cast<unsigned int>(std::round(GetArea() * 4.5));
			break;
		default:
			break;
		}

		return result;
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		return static_cast<unsigned int>(std::ceil(GetArea() / 0.3));
	}
}