#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mElementSize(0)
	{
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mElementSize(other.mElementSize)
	{
		for (size_t i = 0; i < mElementSize; i++)
		{
			mP[i] = other.mP[i];
		}
	}

	PolyLine::~PolyLine()
	{
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mElementSize < MAX_SIZE)
		{
			mP[mElementSize++] = Point(x, y);
			return true;
		}

		return false;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mElementSize < MAX_SIZE)
		{
			mP[mElementSize++] = *point;
			delete point;
			return true;
		}

		return false;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (mElementSize <= i)
		{
			return false;
		}

		for (size_t j = i; j < mElementSize - 1; j++)
		{
			mP[j] = mP[j + 1];
		}

		mElementSize--;
		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		// 점이 최소 2개이상이어야함
		if (mElementSize < 2)
		{
			return false;
		}

		float xValue = 0.f;
		float yValue = 0.f;

		for (size_t i = 0; i < mElementSize; i++)
		{
			if (mP[i].GetX() > xValue)
			{
				xValue = mP[i].GetX();
			}

			if (mP[i].GetY() > yValue)
			{
				yValue = mP[i].GetY();
			}
		}

		Point maxPoint(xValue, yValue);
		*outMax = maxPoint;

		for (size_t i = 0; i < mElementSize; i++)
		{
			if (mP[i].GetX() < xValue)
			{
				xValue = mP[i].GetX();
			}

			if (mP[i].GetY() < yValue)
			{
				yValue = mP[i].GetY();
			}
		}

		Point minPoint(xValue, yValue);
		*outMin = minPoint;

		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (mElementSize <= i)
		{
			return nullptr;
		}

		return &mP[i];
	}
	PolyLine& PolyLine::operator=(const PolyLine& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mElementSize = other.mElementSize;

		for (size_t i = 0; i < mElementSize; i++)
		{
			mP[i] = other.mP[i];
		}

		return *this;
	}
}