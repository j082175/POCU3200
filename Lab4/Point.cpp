#include "Point.h"

namespace lab4
{
	Point::Point()
		: mX(0.f)
		, mY(0.f)
	{}

	Point::Point(float x, float y)
		: mX(x)
		, mY(y)
	{
	}

	Point::~Point()
	{
	}

	Point Point::operator+(const Point& other) const
	{
		return Point(mX + other.mX, mY + other.mY);
	}

	Point Point::operator-(const Point& other) const
	{
		return Point(mX - other.mX, mY - other.mY);
	}

	float Point::Dot(const Point& other) const
	{
		return (mX * other.mX) + (mY * other.mY);
	}

	Point Point::operator*(float operand) const
	{
		return Point(mX * operand, mY * operand);
	}

	float Point::GetX() const
	{
		return mX;
	}

	float Point::GetY() const
	{
		return mY;
	}

	Point operator*(float operand, Point& right)
	{
		return Point(right.mX * operand, right.mY * operand);
	}
}