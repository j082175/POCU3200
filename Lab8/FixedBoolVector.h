#pragma once

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
		uint32_t mArr[N / 32 + (N % CONTROL_POINT ? 1 : 0)];
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
			uint32_t move = 1;
			move = move << mCount % CONTROL_POINT;

			mArr[mCount / CONTROL_POINT] += move;
		}

		++mCount;
		return true;
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Remove(bool t)
	{
		uint32_t move = 1;
		size_t arrLength = mCount / CONTROL_POINT + (mCount % CONTROL_POINT ? 1 : 0);
		size_t lastArrLength = CONTROL_POINT;
		size_t C09checker = 0;

		const uint32_t _UINT32_MAX = 0b10000000'00000000'00000000'00000000;
		const uint32_t _UINT32_MIN = 0b00000000'00000000'00000000'00000001;

		for (size_t i = 0; i < arrLength; i++)
		{
			move = 1;

			if (arrLength == 1)
			{
				lastArrLength = mCount;
			}

			for (size_t j = 0; j < lastArrLength; j++)
			{
				++C09checker;

				if (t && mArr[i % CONTROL_POINT] & move)
				{
					unsigned char isLSB = 0;
					uint32_t left = (mArr[i] >> (j + 1));
					uint32_t right = (mArr[i] << (CONTROL_POINT - j));

					right = (right >> (CONTROL_POINT - j));

					if (j == 0)
					{
						right = 0;
					}

					left = left << j;

					left = left | right;

					if (mCount / CONTROL_POINT)
					{
						if (i < arrLength)
						{
							isLSB = mArr[i + 1] & _UINT32_MIN;
						}
					}

					if (isLSB)
					{
						left |= _UINT32_MAX;
					}

					mArr[i] = left;

					unsigned char isLSB2 = 0;
					size_t k;

					for (k = i + 1; k < arrLength; k++)
					{
						if (k + 1 <= arrLength)
						{
							isLSB2 = mArr[k + 1] & _UINT32_MIN;
						}

						mArr[k] = mArr[k] >> 1;

						if (isLSB2)
						{
							mArr[k] = mArr[k] | _UINT32_MAX;
						}

					}

					--mCount;
					return true;
				}

				if (!t && !(mArr[i % CONTROL_POINT] & move))
				{
					unsigned char isLSB = 0;
					uint32_t left = (mArr[i] >> (j + 1));
					uint32_t right = (mArr[i] << (CONTROL_POINT - j));

					right = (right >> (CONTROL_POINT - j));
					
					if (j == 0)
					{
						right = 0;
					}

					left = left << j;

					left = left | right;

					if (mCount / CONTROL_POINT)
					{
						if (i < arrLength)
						{
							isLSB = mArr[i + 1] & _UINT32_MIN;
						}
					}

					if (isLSB)
					{
						left |= _UINT32_MAX;
					}

					mArr[i] = left;

					unsigned char isLSB2 = 0;
					size_t k;

					// 위의 코드와 다른점
					if (arrLength == 1)
					{
						--mCount;
						return true;
					}

					for (k = i + 1; k < arrLength; k++)
					{
						if (k + 1 <= arrLength)
						{
							isLSB2 = mArr[k + 1] & _UINT32_MIN;
						}

						mArr[k] = mArr[k] >> 1;

						if (isLSB2)
						{
							mArr[k] = mArr[k] | _UINT32_MAX;
						}

					}
					
					--mCount;
					return true;
				}

				if (C09checker == mCount)
				{
					return false;
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