#pragma once
#include "Lawn.h"

namespace lab5
{
	class CircleLawn : public Lawn
	{
	public:
		CircleLawn(unsigned int radius);

		unsigned int GetArea() const; // ��ȯ���� : m^2
	};
}



