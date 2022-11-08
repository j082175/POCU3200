#pragma once

#include "FixedVector.h"

namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();

		bool Add(bool t);

		bool Remove(bool t);

		bool Get(unsigned int index);

		bool operator[](unsigned int index);

		int GetIndex(bool t);

		size_t GetSize();

		size_t GetCapacity();


	private:
		enum
		{
			CONTROL_POINT = 8
		};

		size_t mCount;
		// 8비트
		int32_t mArr[N];

		const unsigned char option0 = 1 << 0; // 0000 0001 
		const unsigned char option1 = 1 << 1; // 0000 0010
		const unsigned char option2 = 1 << 2; // 0000 0100
		const unsigned char option3 = 1 << 3; // 0000 1000
		const unsigned char option4 = 1 << 4; // 0001 0000
		const unsigned char option5 = 1 << 5; // 0010 0000
		const unsigned char option6 = 1 << 6; // 0100 0000
		const unsigned char option7 = 1 << 7; // 1000 0000
	};

	template<size_t N>
	inline FixedVector<bool, N>::FixedVector()
		: mCount(0)
		, mArr{ 0 }
	{}

	template<size_t N>
	inline bool FixedVector<bool, N>::Add(bool t)
	{
		if (mCount >= N)
		{
			return false;
		}

		if (t)
		{
			unsigned char move = 1;
			move = move << mCount % CONTROL_POINT;

			mArr[mCount / CONTROL_POINT] += move;
		}

		++mCount;
		return true;
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Remove(bool t)
	{
		unsigned char move = 1;


		for (size_t i = 0; i < mCount / CONTROL_POINT + mCount % CONTROL_POINT; i++)
		{
			for (size_t j = 0; j < CONTROL_POINT; j++)
			{
				if (mArr[mCount / CONTROL_POINT] & move)
				{

				}
				move = move << 1;
			}
		}


		return false;
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Get(unsigned int index)
	{
		// index 의 값은 항상 범위 내라 가정

		return static_cast<bool>(mArr[index]);
	}

	template<size_t N>
	inline int FixedVector<bool, N>::GetIndex(bool t)
	{

		for (size_t i = 0; i < mCount; i++)
		{
			if (mArr[i] == static_cast<int32_t>(t))
			{
				return i;
			}
		}

		return -1;
	}

	template<size_t N>
	inline size_t FixedVector<bool, N>::GetSize()
	{
		return mCount;
	}

	template<size_t N>
	inline size_t FixedVector<bool, N>::GetCapacity()
	{
		return N;
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::operator[](unsigned int index)
	{
		return static_cast<bool>(mArr[index]);
	}
}