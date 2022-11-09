#pragma once

#include "FixedVector.h"
#include <cmath>

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
			CONTROL_POINT = 32
		};

		size_t mCount;
		// 8비트

		// 4로 나눠야됨
		//uint32_t mArr[N / 32 + (N % CONTROL_POINT ? 1 : 0)];
		uint32_t mArr[N / 32 + 2];

		//const unsigned char option0 = 1 << 0; // 0000 0001 
		//const unsigned char option1 = 1 << 1; // 0000 0010
		//const unsigned char option2 = 1 << 2; // 0000 0100
		//const unsigned char option3 = 1 << 3; // 0000 1000
		//const unsigned char option4 = 1 << 4; // 0001 0000
		//const unsigned char option5 = 1 << 5; // 0010 0000
		//const unsigned char option6 = 1 << 6; // 0100 0000
		//const unsigned char option7 = 1 << 7; // 1000 0000
	};
	
	template<size_t N>
	inline FixedVector<bool, N>::FixedVector()
		: mCount(0)
		//, mArr{ 0 }
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
			int32_t move = 1;
			move = move << mCount % CONTROL_POINT;

			mArr[mCount / CONTROL_POINT] += move;
		}

		++mCount;
		return true;
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Remove(bool t)
	{
		int32_t move = 1;
		size_t length = mCount / CONTROL_POINT + (mCount % CONTROL_POINT ? 1 : 0);
		size_t length2 = CONTROL_POINT;

		for (size_t i = 0; i < length; i++)
		{
			move = 1;

			if (length == 1)
			{
				length2 = mCount;
			}

			for (size_t j = 0; j < length2; j++)
			{
				if (t && mArr[i % CONTROL_POINT] & move)
				{
					uint32_t left = (mArr[i] >> (j + 1));

					uint32_t right = (mArr[i] << (CONTROL_POINT - j));

					right = (right >> (CONTROL_POINT - j));

					if (j == 0)
					{
						right = 0;
					}

					left = left << j;

					left = left | right;

					unsigned char b = 0;

					if (mCount / CONTROL_POINT)
					{
						if (i < length)
						{
							b = mArr[i + 1] & 0b00000000'00000000'00000000'00000001;
						}
					}

					if (b)
					{
						left |= 0b10000000'00000000'00000000'00000000;
					}

					//mArr[i] = left | mArr[i];
					mArr[i] = left;

					unsigned char c = 0;
					size_t k;

					for (k = i + 1; k < length; k++)
					{
						if (k + 1 <= length)
						{
							c = mArr[k + 1] & 0b00000000'00000000'00000000'00000001;
						}

						mArr[k] = mArr[k] >> 1;

						if (c)
						{
							mArr[k] = mArr[k] | 0b10000000'00000000'00000000'00000000;
						}

					}

					//c = mArr[k] & 0b00000000'00000000'00000000'00000001;

					//mArr[k] = mArr[k] >> 1;

					--mCount;
					return true;
				}

				if (!t && !(mArr[i % CONTROL_POINT] & move))
				{
					uint32_t left = (mArr[i] >> (j + 1));
					uint32_t right = (mArr[i] << (CONTROL_POINT - j));

					right = (right >> (CONTROL_POINT - j));
					
					if (j == 0)
					{
						right = 0;
					}

					left = left << j;

					left = left | right;

					unsigned char b = 0;

					if (mCount / CONTROL_POINT)
					{
						if (i < length)
						{
							b = mArr[i + 1] & 0b00000000'00000000'00000000'00000001;
						}
					}

					if (b)
					{
						left |= 0b10000000'00000000'00000000'00000000;
					}

					//mArr[i] = left | mArr[i];
					mArr[i] = left;

					unsigned char c = 0;
					size_t k;

					if (length == 1)
					{
						--mCount;
						return true;
					}

					for (k = i + 1; k < length; k++)
					{
						if (k + 1 <= length)
						{
							c = mArr[k + 1] & 0b00000000'00000000'00000000'00000001;
						}

						mArr[k] = mArr[k] >> 1;

						if (c)
						{
							mArr[k] = mArr[k] | 0b10000000'00000000'00000000'00000000;
						}

					}

					//c = mArr[k] & 0b00000000'00000000'00000000'00000001;

					//mArr[k] = mArr[k] >> 1;
					
					--mCount;
					return true;
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

		size_t idx = index / CONTROL_POINT;
		size_t idx2 = index % CONTROL_POINT;

		uint32_t result = mArr[idx] & static_cast<uint32_t>(std::powl(2, idx2));

		return static_cast<bool>(result);
	}

	template<size_t N>
	inline int FixedVector<bool, N>::GetIndex(bool t)
	{
		size_t length = mCount % CONTROL_POINT;

		size_t i;
		size_t count = 0;

		for (i = 0; i < mCount / CONTROL_POINT; i++)
		{
			for (size_t j = 0; j < CONTROL_POINT; j++)
			{
				if (static_cast<bool>((mArr[i] & static_cast<uint32_t>(std::powl(2, j)))) == t)
				{
					return count;
				}
				++count;
			}
		}

		for (size_t k = 0; k < length; k++)
		{
			if (static_cast<bool>((mArr[i] & static_cast<uint32_t>(std::powl(2, k)))) == t)
			{
				return count;
			}
			++count;
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
		size_t idx = index / CONTROL_POINT;
		size_t idx2 = index % CONTROL_POINT;

		uint32_t result = mArr[idx] & static_cast<uint32_t>(std::powl(2, idx2));

		return static_cast<bool>(result);
	}
}