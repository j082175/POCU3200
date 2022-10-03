#pragma once

#include "eGrassType.h"

namespace lab5
{
	class Lawn
	{
	public:
		Lawn(unsigned width, unsigned height);
		virtual ~Lawn();

		virtual unsigned int GetArea() const = 0;

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;

	protected:
		unsigned int mWidth;
		unsigned int mHeight;
	};
}