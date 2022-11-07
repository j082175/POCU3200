#pragma once

namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();

		bool Add(int32_t t);

		bool Remove(int32_t t);

		int32_t Get(unsigned int index);

		int32_t operator[](unsigned int index);

		int32_t GetIndex(int32_t t);

		size_t GetSize();

		size_t GetCapacity();


	private:
		size_t mCurrentPosition;
		int32_t mArr[N];
	};

	template<size_t N>
	inline FixedVector<bool, N>::FixedVector()
		: mCurrentPosition(0)
		, mArr{ 0 }
	{}

	template<size_t N>
	inline bool FixedVector<bool, N>::Add(int32_t t)
	{
		if (mCurrentPosition >= N)
		{
			return false;
		}

		mArr[mCurrentPosition++] = t;
		return true;
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Remove(int32_t t)
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

	template<size_t N>
	inline int32_t FixedVector<bool, N>::Get(unsigned int index)
	{
		// index 의 값은 항상 범위 내라 가정

		return mArr[index];
	}

	template<size_t N>
	inline int32_t FixedVector<bool, N>::GetIndex(int32_t t)
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

	template<size_t N>
	inline size_t FixedVector<bool, N>::GetSize()
	{
		return mCurrentPosition;
	}

	template<size_t N>
	inline size_t FixedVector<bool, N>::GetCapacity()
	{
		return N;
	}

	template<size_t N>
	inline int32_t FixedVector<bool, N>::operator[](unsigned int index)
	{
		return mArr[index];
	}
}