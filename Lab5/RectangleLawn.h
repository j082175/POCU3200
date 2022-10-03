#pragma once
#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class RectangleLawn : public Lawn, public IFenceable
	{
	public:
		RectangleLawn(unsigned width, unsigned height);

		unsigned int GetArea() const;

		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
	};
}


