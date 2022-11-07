#pragma once
#include "FixedVector.h"

namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector()
			: mCurrentPosition(0)
			, mArr{ 0 }
		{}

		bool Add(bool t)
		{
			if (mCurrentPosition >= N)
			{
				return false;
			}

			mArr[mCurrentPosition++] = t;
			return true;
		}

		bool Remove(bool t)
		{

			for (size_t i = 0; i < mCurrentPosition; i++)
			{
				if (mArr[i] == t)
				{
					for (size_t j = i; j < mCurrentPosition - 1; j++)
					{
						mArr[j] = mArr[j + 1];
					}
					--mCurrentPosition;
					return true;
				}
			}

			return false;
		}

		bool Get(unsigned int index)
		{
			// index 의 값은 항상 범위 내라 가정

			return mArr[index];
		}

		bool operator[](unsigned int index)
		{
			return mArr[index];
		}

		int GetIndex(bool t)
		{

			for (size_t i = 0; i < mCurrentPosition; i++)
			{
				if (mArr[i] == t)
				{
					return i;
				}
			}

			return -1;
		}

		size_t GetSize()
		{
			return mCurrentPosition;
		}

		size_t GetCapacity()
		{
			return N;
		}


	private:
		size_t mCurrentPosition;
		bool mArr[N];
	};

}